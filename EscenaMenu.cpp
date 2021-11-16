#include "EscenaMenu.h"
#include <SFML/Window/Event.hpp>
#include "Juego.h"
#include "EscenaJuego.h"
#include <iostream>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <cstdlib>
#include "EscenaInstrucciones.h"
using namespace std;

EscenaMenu::EscenaMenu(){
	fuente_titulo.loadFromFile("font/D3Euronism.ttf");
	titulo.setFont(fuente_titulo);
	titulo.setString("PROYECTO DE PROGRAMACION");
	titulo.setCharacterSize(34);
	
	titulo.setPosition(40,100);
	titulo2.setFont(fuente_titulo);
	titulo2.setString("ORIENTADA A OBJETOS 2018");
	titulo2.setCharacterSize(34);
	
	titulo2.setPosition(45,150);
	presiona_start.setFont(fuente_titulo);
	presiona_start.setString("Presiona Enter para empezar a jugar");
	presiona_start.setCharacterSize(20);
	presiona_start.setFillColor(Color::Green);
	presiona_start.setPosition(100,450);
	
	presiona_i.setFont(fuente_titulo);
	presiona_i.setString("Presiona I para ver como jugar");
	presiona_i.setCharacterSize(20);
	presiona_i.setFillColor(Color::Green);
	presiona_i.setPosition(125,500);
	
}
void EscenaMenu::actualizar(){
	
	
}

void EscenaMenu::procesar_eventos(RenderWindow &w){
	t=c.getElapsedTime();
	
	if(t.asMilliseconds()>400){
		int i,j,k;
		i=rand()%255;
		j=rand()%255;
		k=rand()%255;
		titulo.setFillColor(Color(i,j,k));
		titulo2.setFillColor(Color(i,j,k));
		c.restart();
	}
//	cout<<"jaj";
//			dibujar(w);
//	if(i==255){
//		i=0;
//	}
		
	
	if(Keyboard::isKeyPressed(Keyboard::I)){
		Juego::getJuego().cambiar_escena(new EscenaInstrucciones());
	}
	if(Keyboard::isKeyPressed(Keyboard::Return)){
		
		Juego::getJuego().cambiar_escena(new EscenaJuego());
	}
}
void EscenaMenu::dibujar(RenderWindow &w){
	w.draw(titulo);
	w.draw(titulo2);
	w.draw(presiona_i);
	w.draw(presiona_start);
}
