#include "EscenaJuego.h"
#include "Entidad.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <sstream>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/System/Clock.hpp>
#include <iostream>
#include "EscenaPuntajes.h"
#include "Juego.h"
#include <vector>
#include <string>
#include <fstream>
#include <unordered_set>

using namespace sf;
using namespace std;

EscenaJuego::EscenaJuego(){
//	ahinco.open("puntajes.txt", ios::app);
	agregar_entidad(p);
	
	tex_gameover.loadFromFile("gameover.png");
	game_over.setTexture(tex_gameover);
	
	tex_gameover2.loadFromFile("gameover2.png");
	game_over2.setTexture(tex_gameover2);
	
	
	
	tex_fondo.loadFromFile("Pared2.png");
	fondo.setTexture(tex_fondo);
	estado=1;
	nivel=1;
	puntos=0;
	puntaje_nivel=puntos;
	velocidad=0;
	fuente.loadFromFile("font/D3Euronism.ttf");
	
	
	puntaje.setFont(fuente);
	puntaje.setCharacterSize(20);
	puntaje.setFillColor(Color::Green);
	puntaje.setPosition(335,18); 
	
	texto_nivel.setFont(fuente);
	texto_nivel.setString("Nivel ");
	texto_nivel.setCharacterSize(20);
	texto_nivel.setFillColor(Color::Blue);
	texto_nivel.setPosition(375,80);
	
	numero_nivel.setFont(fuente);
	numero_nivel.setCharacterSize(20);
	numero_nivel.setFillColor(Color::Blue);
	numero_nivel.setPosition(500,80);
	
	
	texto.setFont(fuente);
	texto.setString("GAME OVER");
	texto.setCharacterSize(40);
	texto.setFillColor(Color::Green);

	
	continuar.setFont(fuente);
	continuar.setString("Pulsa Enter");
	continuar.setCharacterSize(17);
	continuar.setFillColor(Color::Green);
	continuar.setPosition(340,150);
	
	continuar2.setFont(fuente);
	continuar2.setString("para continuar");
	continuar2.setCharacterSize(17);
	continuar2.setFillColor(Color::Green);
	continuar2.setPosition(335,170);
}
void EscenaJuego::procesar_eventos(RenderWindow &w){
	
	
	
	t=c.getElapsedTime();

	float tim = t.asSeconds();
	

	
	switch(estado){
	case 1:
		
		pieza_esperando();
	
		if(p->ternapuedecaer()==false){
			if(t.asMilliseconds()>(1000)){
				if(p->chequear()){
					actualizar();
					estado=2;
				}else if(p->no_puede_crear_terna()){
					ordenar_puntajes();
					actualizar();
					dibujar(w);
					estado=4;
				} else{
					actualizar();
					p->nueva_terna();
				}
			}
		}else if(t.asMilliseconds()>(1000-velocidad)){
			
			actualizar();
			c.restart();
		}
		////SI LA TECLA S ESTA APRETADA, LA TERNA CAE MAS RAPIDO
		else if(Keyboard::isKeyPressed(Keyboard::S) ){
			
			if(t.asMilliseconds()>15){
				actualizar();
				c.restart();
			}
		}
		dibujar(w);
		break;
	case 2:
		
		if(t.asMilliseconds()>40){
			dibujar(w);
			p->get_textura()++;
			if(p->get_textura()==8){
				p->get_textura()=1;
				estado=3;
				
			}
			c.restart();
		}
		
		break;
	case 3:
		p->match();
		puntos+=2*p->get_filas().size();
		if(puntos>=(puntaje_nivel+30)&& puntos!=0){
			if(!aceleracion){
				aceleracion=true;
				cout<<"mas rapido!"<<endl;
				velocidad+=100;
				puntaje_nivel+=30;
				nivel++;
			} else{
				aceleracion=false;
			}
			
		}
		p->bajar_luces();
		p->nueva_terna();
		p->pasar_estado(3);
		actualizar();
		
		c.restart();
		
		if(p->chequear()){
		estado=2;
		}else{
			p->pasar_estado(1);
			estado=1;
		}
		dibujar(w);	
		break;
	case 4: 
		
		if(t.asSeconds()>1){
			switch(estado_gameover){
			case 1:
				estado_gameover=2;
				break;
			case 2:
				estado_gameover=1;
				break;
			}
			c.restart();
		}
		if(Keyboard::isKeyPressed(Keyboard::Return)){
			
			Juego::getJuego().cambiar_escena(new EscenaPuntajes());
			break;
		}
	}

	
}

void EscenaJuego::actualizar(){
	
	stringstream tmp,tmp2;
	tmp<<"Puntaje:"<<puntos;
	tmp2<<nivel;
	puntaje.setString(tmp.str());
	numero_nivel.setString(tmp2.str());

	if(nivel>=4 && nivel<7){
		texto_nivel.setFillColor(Color::Green);
		numero_nivel.setFillColor(Color::Green);
	}else if(nivel>=7 && nivel<10){
		texto_nivel.setFillColor(Color::Yellow);
		numero_nivel.setFillColor(Color::Yellow);
	}else if(nivel>=10){
		texto_nivel.setFillColor(Color::Red);
		numero_nivel.setFillColor(Color::Red);
	}
	
	EscenaBase::actualizar();

}






void EscenaJuego::pieza_esperando(){
	/////SI SE APRIETA LA TECLA D, LA TERNA SE MUEVE A LA DERECHA
	if(Keyboard::isKeyPressed(Keyboard::D)){
		if(!tecla_D){
			tecla_D=true;
			p->terna_moverder();
		}
	}else{
		tecla_D=false;
	}
	/////SI SE APRIETA LA TECLA A, LA TERNA SE MUEVE A LA IZQUIERDA
	if(Keyboard::isKeyPressed(Keyboard::A)){
		if(!tecla_A){
			tecla_A=true;
			p->terna_moverizq();
		}
	}else{
		tecla_A=false;
	}
	
	/////SI SE APRIETA LA TECLA I, SE INTERCAMBIAN LAS POSICIONES DE LAS LUCES DE LA TERNA
	if(Keyboard::isKeyPressed(Keyboard::I)){
		if(!tecla_I){
			tecla_I=true;
			p->get_terna().intercambiar();
			
		}
	}else{
		tecla_I=false;
	}
}












void EscenaJuego::ordenar_puntajes(){
//	if(!ahinco.is_open()){
//		cout<<"Oh nooooo";
//	}else{
//		ahinco<<puntos;
//		ahinco.close();
//		
//	}

	ifstream archivo_lectura("puntajes.txt");
	vector<int>records;
	string i;
	vector<string>::iterator p,q;
	string::size_type sz;
	while(getline(archivo_lectura,i)){
		int i_ent=atoi(i.c_str());
		records.push_back(i_ent);
		cout<<i<<endl;
	}
	
	
	
	sort(records.begin(),records.end());
	reverse(records.begin(),records.end());
	archivo_lectura.close();
	ofstream archivo_escritura("puntajes.txt");
	for(int i=0;i<records.size();i++) { 
		archivo_escritura<<records[i]<<endl;
	}
	archivo_escritura.close();
}


void EscenaJuego::dibujar(RenderWindow &w){
	w.clear(sf::Color::Black);
	w.draw(fondo);
	

	w.draw(texto_nivel);
	w.draw(numero_nivel);
	EscenaBase::dibujar(w);
	
	
	if(estado==4){
		int i=rand()%255;
		int j=rand()%255;
		int k=rand()%255;
		puntaje.setFillColor(Color(i,j,k));
		if(estado_gameover==1){
			game_over.setPosition(10,200);
			w.draw(game_over);
		}else if(estado_gameover==2){
			game_over2.setPosition(10,200);
			w.draw(game_over2);
		}
		
		w.draw(continuar);
		w.draw(continuar2);
	}
	w.draw(puntaje);
	w.display();
}
