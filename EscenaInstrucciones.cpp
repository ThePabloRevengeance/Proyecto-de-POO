#include <SFML/Window/Event.hpp>
#include "Juego.h"
#include "EscenaJuego.h"
#include <iostream>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <cstdlib>
#include "EscenaInstrucciones.h"
#include "EscenaMenu.h"
using namespace std;

EscenaInstrucciones::EscenaInstrucciones(){
	pagina=1; 
	
	t1.loadFromFile("Instrucciones 1.png");
	s1.setTexture(t1);
	s1.setPosition(0,330);
	
	t2.loadFromFile("Instrucciones2.png");
	s2.setTexture(t2);
	
	t3.loadFromFile("Instrucciones 3.png");
	s3.setTexture(t3);
	s3.setPosition(80,0);
	
	t4.loadFromFile("Instrucciones 4.png");
	s4.setTexture(t4);
	s4.setPosition(280,350);
	
	fuente.loadFromFile("font/D3Euronism.ttf");
	
	
	mover_izq.setFont(fuente);
	mover_izq.setString("Pulsa A para moverte a la izquierda");
	mover_izq.setCharacterSize(13);
	mover_izq.setPosition(0,600);
	
	
	mover_der.setFont(fuente);
	mover_der.setString("Pulsa D para moverte a la derecha");
	mover_der.setCharacterSize(13);
	mover_der.setPosition(450,600);
	
	
	descender_rapido.setFont(fuente);
	descender_rapido.setString("Pulsa S para bajar mas rapido");
	descender_rapido.setCharacterSize(14);
	descender_rapido.setPosition(470,275);
	
	rotar_luces.setFont(fuente);
	rotar_luces.setString("Pulsa I para cambiar el orden");
	rotar_luces.setCharacterSize(13);
	rotar_luces.setPosition(10,275);
	rotar_luces2.setFont(fuente);
	rotar_luces2.setString("de las luces de la terna");
	rotar_luces2.setCharacterSize(13);
	rotar_luces2.setPosition(20,287);
	
	juntar_luces.setFont(fuente);
	juntar_luces.setString("Si se juntan un minimo de 3 luces de un mismo color, ya");
	juntar_luces.setCharacterSize(17);
	juntar_luces.setPosition(43,275);
	
	juntar_luces2.setFont(fuente);
	juntar_luces2.setString("sea de manera vertical u horizontal, se preduce un MATCH!");
	juntar_luces2.setCharacterSize(17);
	juntar_luces2.setPosition(35,295);
	
	juntar_luces3.setFont(fuente);
	juntar_luces3.setString(" Por cada MATCH que el jugador haga, su puntaje aumenta" );
	juntar_luces3.setCharacterSize(17);
	juntar_luces3.setPosition(30,420);
	
	objetivo.setFont(fuente);
	objetivo.setString("El objetivo del juego es conseguir la mayor");
	objetivo.setCharacterSize(21);
	objetivo.setFillColor(Color::Cyan);
	objetivo.setPosition(55,490);
	
	objetivo2.setFont(fuente);
	objetivo2.setString("puntuacion posible antes de que el pozo se llene");
	objetivo2.setCharacterSize(21);
	objetivo2.setFillColor(Color::Cyan);
	objetivo2.setPosition(20,510);
	
	volver.setFont(fuente);
	volver.setString("Q para volver al menu");
	volver.setCharacterSize(16);
	volver.setFillColor(Color::Green);
	volver.setPosition(0,640);
	
	
	continuar.setFont(fuente);
	continuar.setString("E para continuar");
	continuar.setCharacterSize(16);
	continuar.setFillColor(Color::Green);
	continuar.setPosition(600,640);
	
	
	
	
}
void EscenaInstrucciones::actualizar(){
	
	
}

void EscenaInstrucciones::procesar_eventos(RenderWindow &w){
	
	if(Keyboard::isKeyPressed(Keyboard::Q)){
		
		Juego::getJuego().cambiar_escena(new EscenaMenu());
	}else if(Keyboard::isKeyPressed(Keyboard::E)){
		pagina=2;
	}
}
void EscenaInstrucciones::dibujar(RenderWindow &w){
	if(pagina==1){
		w.draw(mover_izq);
		w.draw(mover_der);
		w.draw(s1);
		w.draw(s2);
		w.draw(descender_rapido);
		w.draw(rotar_luces);
		w.draw(rotar_luces2);
		w.draw(volver);
		w.draw(continuar);
	}else if(pagina==2){
		w.draw(s3);
		w.draw(s4);
		w.draw(juntar_luces);
		w.draw(juntar_luces2);
		w.draw(juntar_luces3);
		w.draw(objetivo);
		w.draw(objetivo2);
		w.draw(volver);
	}
	
}
