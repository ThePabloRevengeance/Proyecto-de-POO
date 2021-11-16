#include "Juego.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Color.hpp>
#include "terna.h"
#include <SFML/System/Vector2.hpp>
#include <iostream>
#include <ctime>
#include <SFML/System/Time.hpp>
#include <sstream>
#include "EscenaBase.h"



using namespace sf;
using namespace std;
Juego *Juego::instance = nullptr;
Juego::Juego() {};

Juego &Juego::crear(const VideoMode &videomode, EscenaBase *escena, const string &nombre){
	if(instance){
		cout<<"ERROR"<<endl;
	}else{
		Juego &j=getJuego();
		j.w.create(videomode, nombre, sf::Style::Close);
		j.siguienteEscena = nullptr;
		j.EscenaActual = escena;
		j.w.setFramerateLimit(60);
		j.c.restart();
	}
	return getJuego();
}

Juego &Juego::getJuego(){
	if(!instance){
		instance = new Juego();
	}
	return *instance;
}
void Juego::run(){
	w.setFramerateLimit(60);
	while(w.isOpen() && EscenaActual != nullptr) {
		Event e;
		while(w.pollEvent(e)){
			if(e.type == Event::Closed){
				w.close();
			}
		}
		if(Keyboard::isKeyPressed(Keyboard::Escape)){
			w.close();
		}
		if (e.type==Event::Resized){
			//			cout<<"Nueva anchura: "<<e.size.width<<endl;
			//			cout<<"Nueva altura: "<<e.size.height<<endl;
		}
		if(e.type==Event::LostFocus){//para pausar de juego cuando se selecciona otra ventana
			//			.pause();
		}
		if(e.type==e.TextEntered){
			if(e.text.unicode<128){
				//				cout<<"Caracter del codigo ASCII: ";
			}
		}
		procesar_eventos();
//		actualizar();
		dibujar();
		if(siguienteEscena != nullptr){
			delete EscenaActual;
			EscenaActual = siguienteEscena;
			siguienteEscena = nullptr;
		}
	}
	EscenaActual->limpiar_entidades();
}
void Juego::procesar_eventos(){
	EscenaActual->procesar_eventos(w);
}
void Juego::cambiar_escena(EscenaBase *escena){
	siguienteEscena=escena;
}

void Juego::actualizar(){
	EscenaActual->actualizar();
}

void Juego::dibujar(){
	w.clear(Color(0,0,0,255));
	EscenaActual->dibujar(w);
	w.display();
}



