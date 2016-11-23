#include <iostream>
#include "libraries/ClaseControles.h"
#include "libraries/ClaseGraficos.h"
#include "STATICS/mappedResource.h"
#include <string.h>
#include "Game/mainMenu.h"

int main(){
	//Crear clase graficos
	Graficos CGraficos(false, 400, 300, true);

	//Crear clase controles
	Controles CControles(CGraficos, true);

	//Llamamos a main menu
	mainMenu(CGraficos, CControles);
}
