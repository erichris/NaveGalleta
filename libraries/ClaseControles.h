#ifndef CLASECONTROLES_H
#define CLASECONTROLES_H

#include <SFML/Graphics.hpp>
#include <string.h>
#include <iostream>
using namespace std;
using namespace sf;

class Controles : public Event, public Mouse {
public:
	Controles(RenderWindow& ActualWindow, bool status_debug = true);
	void set_window(RenderWindow&);
	void set_debug(bool);
	string get_evento_actual();
	bool esta_dentro_de(int, int, int, int); //X, Y, SX, SY
	void debug_message(string);
private:
	bool debug;
	Event Events;
	RenderWindow& Window;
};

#endif
