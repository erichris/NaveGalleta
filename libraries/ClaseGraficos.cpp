#include "ClaseGraficos.h"

//INIT
Graficos::Graficos(bool status_fullscreen, int largo_pantalla, int ancho_pantalla, bool status_debug){
	set_debug(status_debug);
	set_fullscreen(status_fullscreen);
	set_largo(largo_pantalla);
	set_ancho(ancho_pantalla);
	set_frame_rate(30);
	return;
}
//Funciones
void Graficos::crear_ventana(string nombre_ventana){
	//Se crea la ventana y se checa si el modo fullscreen esta activo
	if( fullscreen == true ){
		create(sf::VideoMode(largo, ancho), nombre_ventana, sf::Style::Fullscreen);
	}
	else{
		create(sf::VideoMode(largo, ancho), nombre_ventana, sf::Style::Close);
	}
}
bool Graficos::verificar_si_esta_abierta(){
	return isOpen();
}
void Graficos::set_frame_rate(int fps){
	setFramerateLimit(fps);
	return;
}
int Graficos::get_ancho_pantalla(){
	return ancho;
}
int Graficos::get_largo_pantalla(){
	return largo;
}
void Graficos::debug_message(string mensaje){
	if( debug == true ){
		cout << mensaje << endl;
	}
	return;
}
void Graficos::set_ancho(int ancho_pantalla){
	ancho = ancho_pantalla;
	return;
}
void Graficos::set_largo(int largo_pantalla){
	largo = largo_pantalla;
	return;
}
void Graficos::set_fullscreen(bool status_fullsccreen){
	fullscreen = status_fullsccreen;
	return;
}
void Graficos::set_debug(bool status_debugger){
	debug = status_debugger;
	return;
}
//Graficos
void Graficos::limpiar_pantalla(){
	clear(sf::Color::Black);
	return;
}
void Graficos::renderizar_pantalla(){
	display();
	return;
}












