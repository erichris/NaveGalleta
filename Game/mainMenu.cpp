#include "mainMenu.h"

#include "exitGame.h"
#include "startGame.h"

string evento_actual;
int opcion_selecionable = 0;
int cantidad_opciones = 5;
int movimiento_cursor = 50;

Texture BackgroundMenuTexture;
Texture BotonStartGameTexture;
Texture BotonInstruccionesTexture;
Texture BotonCreditosTexture;
Texture BotonHighScoreTexture;
Texture BotonExitTexture;
Texture CursorSelectorTexture;

Sprite BackgroundMenu;
Sprite BotonStartGame;
Sprite BotonInstrucciones;
Sprite BotonCreditos;
Sprite BotonHighScore;
Sprite BotonExit;
Sprite CursorSelector;

int Background_x 		= 0;
int Background_y 		= 0;
int BotonStartGame_x 	= 150;
int BotonStartGame_y 	= 50;
int BotonExit_x 		= 150;
int BotonExit_y	 		= 250;
int BotonHighScore_x 	= 150;
int BotonHighScore_y 	= 150;
int BotonInstrucciones_x= 150;
int BotonInstrucciones_y= 100;
int BotonCreditos_x 	= 150;
int BotonCreditos_y 	= 200;
int CursorSelector_x 	= 110;
int CursorSelector_y 	= 50;

void modelMainMenu();
void viewMainMenu(Graficos& CGraficos);
void controllerMainMenu(Graficos&, Controles&);

void mainMenu(Graficos& CGraficos, Controles& CControles){

	//Mapeado
	map<string, string> STATICS = get_statics();

	BackgroundMenuTexture.loadFromFile        (STATICS["BackgroundMenu"]);
	BotonStartGameTexture.loadFromFile        (STATICS["BotonJugar"]);
	BotonInstruccionesTexture.loadFromFile    (STATICS["BotonInstrucciones"]);
	BotonCreditosTexture.loadFromFile         (STATICS["BotonCreditos"]);
	BotonHighScoreTexture.loadFromFile        (STATICS["BotonHighScore"]);
	BotonExitTexture.loadFromFile             (STATICS["BotonSalir"]);
	CursorSelectorTexture.loadFromFile        (STATICS["CursorMainMenu"]);

	BackgroundMenu.setTexture		(BackgroundMenuTexture);
	BotonStartGame.setTexture		(BotonStartGameTexture);
	BotonInstrucciones.setTexture	(BotonInstruccionesTexture);
	BotonCreditos.setTexture		(BotonCreditosTexture);
	BotonHighScore.setTexture		(BotonHighScoreTexture);
	BotonExit.setTexture			(BotonExitTexture);
	CursorSelector.setTexture		(CursorSelectorTexture);

	//Empezar ventana
	CGraficos.crear_ventana("Testing");

	while(CGraficos.verificar_si_esta_abierta()){
		modelMainMenu();
		viewMainMenu(CGraficos);
		controllerMainMenu(CGraficos, CControles);
	}
}

void modelMainMenu(){
	BackgroundMenu.setPosition(Background_x, Background_y);
	BotonStartGame.setPosition(BotonStartGame_x, BotonStartGame_y);
	BotonInstrucciones.setPosition(BotonInstrucciones_x, BotonInstrucciones_y);
	BotonCreditos.setPosition(BotonCreditos_x, BotonCreditos_y);
	BotonHighScore.setPosition(BotonHighScore_x, BotonHighScore_y);
	BotonExit.setPosition(BotonExit_x, BotonExit_y);
	CursorSelector.setPosition(CursorSelector_x, CursorSelector_y);
}

void viewMainMenu(Graficos& CGraficos){
	CGraficos.limpiar_pantalla();
	CGraficos.draw(BackgroundMenu);
	CGraficos.draw(BotonStartGame);
	CGraficos.draw(BotonInstrucciones);
	CGraficos.draw(BotonCreditos);
	CGraficos.draw(BotonHighScore);
	CGraficos.draw(BotonExit);
	CGraficos.draw(CursorSelector);
	CGraficos.renderizar_pantalla();
}

void controllerMainMenu(Graficos& CGraficos, Controles& CControles){
	evento_actual = CControles.get_evento_actual();
	if(evento_actual == "TeclaPresionada S" || evento_actual == "TeclaPresionada FlechaAbajo"){ // Se mueve el cursor de seleccion hacia abajo
		if( opcion_selecionable < cantidad_opciones - 1){
			CursorSelector_y += movimiento_cursor;
			opcion_selecionable += 1;
		}
	}
	else if(evento_actual == "TeclaPresionada W" || evento_actual == "TeclaPresionada FlechaArriba"){ //Se mueve el cursor de seleccion hacia arriba
		if( opcion_selecionable > 0){
			CursorSelector_y -= movimiento_cursor;
			opcion_selecionable -=1;
		}
	}
	else if(evento_actual ==  "TeclaPresionada Espacio" || evento_actual ==  "TeclaPresionada Enter"){
		if( opcion_selecionable == 0 ){
			cout << "Iniciar Juego" << endl;
			startGame(CGraficos, CControles);
		}
		else if( opcion_selecionable == 1 ){
			cout << "Instrucciones" << endl;
		}
		else if( opcion_selecionable == 2 ){
			cout << "High Score" << endl;
		}
		else if( opcion_selecionable == 3 ){
			cout << "Creditos" << endl;
		}
		else if( opcion_selecionable == 4 ){
			cout << "Salir" << endl;
			salir();
		}
	}
	else if(evento_actual == "TeclaPresionada Escape"){ //Salida juego
		salir();
	}
}
