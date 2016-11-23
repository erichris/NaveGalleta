#ifndef CLASEGRAFICOS_H
#define CLASEGRAFICOS_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string.h>
#include <iostream>

using namespace std;
using namespace sf;

class Graficos: public RenderWindow{
public:
	//Init
	Graficos(bool status_fullscreen = false, int largo_pantalla = 800, int ancho_pantalla = 600, bool status_debug = true);

	//Funciones
	void crear_ventana(string);
	bool verificar_si_esta_abierta();
	void set_ancho(int); //width
	void set_largo(int); //Height
	void set_fullscreen(bool); //fullscreen_status
	void set_debug(bool); //debug_status
	void set_frame_rate(int); //Frame_rate
	int get_ancho_pantalla();
	int get_largo_pantalla();
	void debug_message(string);

	//Graficos
	void limpiar_pantalla();
	void renderizar_pantalla();

	//Parametros
private:
	//Parametros
	bool debug;
	bool fullscreen;
	int largo;
	int ancho;
};

#endif
