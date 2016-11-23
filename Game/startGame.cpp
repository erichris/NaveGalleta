#include "startGame.h"

#include "exitGame.h"

string eventoStartGame;
float time_passed;

Clock DeltaClock;
Time DeltaTime;

Texture BackgroundTexture;
Texture Enemy1Texture;

Sprite EnemySprite;
Sprite BackGroundSprite;

Enemigo Enemy(200, 0, 0, 0, 0);

int Enemy1_x = 0;
int Enemy1_y = 0;
int Background_x_ = 0;
int Background_y_ = 0;

void modelStartGame();
void viewStartGame(Graficos&);
void controllerStartGame(Controles&);

void startGame(Graficos& CGraficos, Controles CControles){
	//Mapeado
	map<string, string> STATICS = get_statics();

	Enemy1Texture.loadFromFile		(STATICS["EnemyShip1"]);
	BackgroundTexture.loadFromFile	(STATICS["BackgroundMenu"]);

	EnemySprite.setTexture			(Enemy1Texture);
	BackGroundSprite.setTexture		(BackgroundTexture);

	BackGroundSprite.setPosition(Background_x_, Background_y_);

	Enemy.set_sprite(EnemySprite);

	Time DeltaTime = DeltaClock.restart();
	time_passed = DeltaTime.asSeconds();
	while(CGraficos.isOpen()){
		Time DeltaTime = DeltaClock.restart();
		time_passed = DeltaTime.asSeconds();
		modelStartGame();
		viewStartGame(CGraficos);
		controllerStartGame(CControles);
	}
}
void modelStartGame(){
	Enemy.mover(time_passed);
}
void viewStartGame(Graficos& CGraficos){
	CGraficos.limpiar_pantalla();
	CGraficos.draw(BackGroundSprite);
	Enemy.dibujar_enemigo(CGraficos);
	CGraficos.renderizar_pantalla();
}
void controllerStartGame(Controles& CControles){
	eventoStartGame = CControles.get_evento_actual();
	if(eventoStartGame == "TeclaPresionada Escape"){
		salir();
	}
}
