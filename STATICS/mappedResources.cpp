#include "mappedResource.h"
#include <string.h>

using namespace std;

typedef map<string, string> BasePairMap;

string RUTA_BASE = "STATICS\\";

int SIZE_STATICS = 8;

string STATICS_[] = {
		"Backgrounds\\fondo_colombia.png",
		"Others\\boton_creditos.png",
		"Others\\boton_high_score.png",
		"Others\\boton_instrucciones.png",
		"Others\\boton_jugar.png",
		"Others\\boton_salir.png",
		"Sprites\\cursor_game.png",
		"Sprites\\Enemy_Ship_1.png",
};

string KEY_STATICS[] = {
		"BackgroundMenu",
		"BotonCreditos",
		"BotonHighScore",
		"BotonInstrucciones",
		"BotonJugar",
		"BotonSalir",
		"CursorMainMenu",
		"EnemyShip1",
};

map<string, string> get_statics(){
	BasePairMap STATICS;
	//STATICS["Hola"] = "Adios";
	for( int element = 0; SIZE_STATICS > element; element++ ){
		STATICS[KEY_STATICS[element]] = RUTA_BASE + STATICS_[element];
	}
	return STATICS;
}
