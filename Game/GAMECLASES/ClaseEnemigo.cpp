#include "ClaseEnemigo.h";

//INIT
Enemigo::Enemigo(float vx, float vy, float x, float y, float angulo){
	set_x(x);
	set_y(y);
	set_angulo(angulo);
	set_velocidad_x(vx);
	set_velocidad_y(vy);
}
void Enemigo::set_hp(int hp_){
	hp = hp_;
	return;
}
void Enemigo::set_x(float x_){
	x = x_;
	return;
}
void Enemigo::set_y(float y_){
	y = y_;
	return;
}
void Enemigo::set_angulo(float angulo_){
	angulo = angulo_;
	return;
}
void Enemigo::set_velocidad_x(float velocidad_x_){
	velocidad_x = velocidad_x_;
	return;
}
void Enemigo::set_velocidad_y(float velocidad_y_){
	velocidad_y = velocidad_y_;
	return;
}
int Enemigo::get_hp(){
	return hp;
}
float Enemigo::get_x(){
	return x;
}
float Enemigo::get_y(){
	return y;
}
float Enemigo::get_angulo(){
	return angulo;
}
void Enemigo::set_sprite(Sprite EnemySprite_){
	EnemySprite = EnemySprite_;
	return;
}

//Funciones
void Enemigo::dibujar_enemigo(RenderWindow& Window){
	Window.draw(EnemySprite);
	return;
}
void Enemigo::establecer_posicion(float x_, float y_){
	x = x_;
	y = y_;
	EnemySprite.setPosition(x, y);
}
void Enemigo::rotar(float angulo_){
	EnemySprite.rotate(angulo_);
	angulo += angulo_;
	return;
}
void Enemigo::disparar(){
	cout << "Se disparo" << endl;
	return;
}
void Enemigo::mover(float time_passed){
	if(x >= 400 - EnemySprite.getGlobalBounds().height || x < 0){
		velocidad_x *= -1;
	}
	x = x+time_passed*velocidad_x;
	y = y+time_passed*velocidad_y;
	EnemySprite.setPosition(x, y);
}

void Enemigo::colision_damage(){
	//Bajar HP
	if(hp == 0){
		//Destruir objeto
	}
}
void Enemigo::destructor(){
	//Destructor de objeto
}
