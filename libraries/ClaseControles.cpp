#include "ClaseControles.h"

string devolver_valor_tecla(Event);
string devolver_boton_mouse(Event);

Controles::Controles(RenderWindow& VentanaActual, bool status_debug): Window(VentanaActual){
	//set_window(VentanaActual);
	set_debug(status_debug);
}

//void Controles::set_window(RenderWindow& actual_window){
	//Window* actual_window;
	//return;
//}

void Controles::set_debug(bool status_debug){
	debug = status_debug;
	return;
}

void Controles::debug_message(string mensaje){
	if(debug == true){
		cout << mensaje << endl;
	}
	return;
}

bool Controles::esta_dentro_de(int x, int y, int sx, int sy){
	Vector2i posicion;
	posicion = getPosition(Window);
	//cout << posicion.x << " " << posicion.y << endl;
	if(x < posicion.x && x + sx > posicion.x && y < posicion.y && y + sy > posicion.y){
		//cout << "Dentro" << endl;
		return true;
	}
	else{
		//cout << "Fuera" << endl;
		return false;
	}
}

string Controles::get_evento_actual(){
	//Evalua si se ha realizado alguna accion

	string actual_event;
	if(Window.pollEvent(Events) != false){
		switch( Events.type ){
			//case(Event::MouseMoved): //Mouse se movio
			//	actual_event = "MouseMove";
			//	break;
			case(Event::MouseButtonPressed): //Boton mouse presionado
				actual_event = "MousePresionado ";
				actual_event += devolver_boton_mouse(Events);
				break;
			case(Event::MouseButtonReleased): // Boton mouse liberado
				actual_event = "MouseLiberado ";
				actual_event += devolver_boton_mouse(Events);
				break;
			case(Event::KeyPressed): //Boton teclado presionado
				actual_event = "TeclaPresionada ";
				actual_event += devolver_valor_tecla(Events);
				break;
			case(Event::KeyReleased): //Boton teclado liberado
				actual_event = "TeclaLiberada ";
				actual_event += devolver_valor_tecla(Events);
				break;
			case(Event::Closed): //Cierre de ventana
				actual_event = "Close";
				break;
			case(Event::LostFocus): //Se salio de la ventana
				actual_event = "PerdioFocus";
				break;
			case(Event::GainedFocus): //Se regreso a la ventana
				actual_event =  "GanoFocus";
				break;
			default: //Cualquier otra cosa
				actual_event = "";
		}
	}
	if(actual_event != "") debug_message(actual_event);
	return actual_event;
}

string devolver_boton_mouse(Event Events){
	string boton = "";
	switch(Events.mouseButton.button){
		case(Mouse::Right):
			boton = "Derecho";
			break;
		case(Mouse::Left):
			boton = "Izquierdo";
			break;
		default:
			boton = "other";
			break;
	}
	return boton;
}

string devolver_valor_tecla(Event Events){
	string tecla = "";
	switch(Events.key.code){
		case(Keyboard::A):
			tecla = "A";
			break;
		case(Keyboard::B):
			tecla = "B";
			break;
		case(Keyboard::C):
			tecla = "C";
			break;
		case(Keyboard::D):
			tecla = "D";
			break;
		case(Keyboard::E):
			tecla = "E";
			break;
		case(Keyboard::F):
			tecla = "F";
			break;
		case(Keyboard::G):
			tecla = "G";
			break;
		case(Keyboard::H):
			tecla = "H";
			break;
		case(Keyboard::I):
			tecla = "I";
			break;
		case(Keyboard::J):
			tecla = "J";
			break;
		case(Keyboard::K):
			tecla = "K";
			break;
		case(Keyboard::L):
			tecla = "L";
			break;
		case(Keyboard::M):
			tecla = "M";
			break;
		case(Keyboard::N):
			tecla = "N";
			break;
		case(Keyboard::O):
			tecla = "O";
			break;
		case(Keyboard::P):
			tecla = "P";
			break;
		case(Keyboard::Q):
			tecla = "Q";
			break;
		case(Keyboard::R):
			tecla = "R";
			break;
		case(Keyboard::S):
			tecla = "S";
			break;
		case(Keyboard::T):
			tecla = "T";
			break;
		case(Keyboard::U):
			tecla = "U";
			break;
		case(Keyboard::V):
			tecla = "V";
			break;
		case(Keyboard::W):
			tecla = "W";
			break;
		case(Keyboard::X):
			tecla = "X";
			break;
		case(Keyboard::Y):
			tecla = "Y";
			break;
		case(Keyboard::Z):
			tecla = "Z";
			break;
		case(Keyboard::Escape):
			tecla = "Escape";
			break;
		case(Keyboard::Space):
			tecla = "Espacio";
			break;
		case(Keyboard::Down):
			tecla = "FlechaAbajo";
			break;
		case(Keyboard::Up):
			tecla = "FlechaArriba";
			break;
		case(Keyboard::Right):
			tecla = "FlechaDerecha";
			break;
		case(Keyboard::Left):
			tecla = "FlechaIzquierda";
			break;
		case(Keyboard::BackSpace):
			tecla = "Borrar";
			break;
		case(58):
			tecla = "Enter";
			break;
		default:
			//cout << Events.key.code << endl;
			tecla = "Other";
			break;
	}
	return tecla;
}
