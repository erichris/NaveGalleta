#ifndef CLASEENEMIGO_H
#define CLASEENEMIGO_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>

using namespace std;
using namespace sf;

class Enemigo: public Sprite{
public:
	//INIT
	Enemigo(float vx = 0, float vy = 0, float x = 0, float y = 0, float angulo = 0);
	void set_hp(int);
	void set_x(float);
	void set_y(float);
	void set_angulo(float);
	void set_velocidad_x(float);
	void set_velocidad_y(float);
	int get_hp();
	float get_x();
	float get_y();
	float get_angulo();
	void set_sprite(Sprite);
	//Funciones
	void dibujar_enemigo(RenderWindow&);
	void establecer_posicion(float, float);
	void rotar(float);
	void mover(float);
	void disparar();
	//Destructor
	void colision_damage();
	void destructor();
private:
	int hp;
	float x;
	float y;
	float velocidad_x;
	float velocidad_y;
	float angulo;
	Sprite EnemySprite;
};

#endif
