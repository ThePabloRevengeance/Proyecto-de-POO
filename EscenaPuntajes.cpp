
#include "Juego.h"
#include "EscenaPuntajes.h"
#include "EscenaJuego.h"
#include <iostream>
#include <sstream>
#include "EscenaMenu.h"

using namespace std;

EscenaPuntajes::EscenaPuntajes(){
	archivo.open("puntajes.txt"/*,ios::binary|ios::in*/);
	fuente_texto.loadFromFile("font/D3Euronism.ttf");
	mejores_puntajes.setFont(fuente_texto);
	mejores_puntajes.setString("Puntuaciones mas altas");
	mejores_puntajes.setCharacterSize(40);
	mejores_puntajes.setFillColor(Color::Green);
	mejores_puntajes.setPosition(70,100);
	presiona_start.setFont(fuente_texto);
	presiona_start.setString("Presiona Q para volver al menu principal");
	presiona_start.setCharacterSize(15);
	presiona_start.setFillColor(Color::Green);
	presiona_start.setPosition(150,650);
}
void EscenaPuntajes::actualizar(){

//	archivo.close();
}

void EscenaPuntajes::procesar_eventos(RenderWindow &w){
	if(!archivo.is_open()){
		cout<<"Que problemita!";
	}
	string i;
//	archivo.seekg(0,ios::end);
//	int tam=archivo.tellg();
//	int cantidad=tam/sizeof(i);
//	archivo.seekg(0,ios::beg);
//	cout<<"-"<<cantidad<<"-"<<endl;
	while(getline(archivo,i) && v.size()<5){
		v.push_back(i);
	}
//		archivo.read(reinterpret_cast<char*>(&i),sizeof(i));
		/*cout<<i<<endl;*/
		
//		cout<<"-"<<cantidad<<"-";
//		v[i].setString(tmp.str());
//		puntuaciones.setPosition(200,250/*+50*i*/);
//		dibujar(w);
	
	/*archivo.close();*/
	/*cout<<"-"<<cantidad<<"-";*/
	
	if(Keyboard::isKeyPressed(Keyboard::Q)){
		
		Juego::getJuego().cambiar_escena(new EscenaMenu());
	}
}
void EscenaPuntajes::dibujar(RenderWindow &w){
	w.draw(mejores_puntajes);
	Text tex[v.size()];
	for(int i=0;i<v.size();i++) { 
		stringstream tmp;
		tmp<<"Puntaje:            "<<v[i];
		tex[i].setFont(fuente_texto);
		tex[i].setCharacterSize(25);
		tex[i].setString(tmp.str());
		tex[i].setPosition(150,250+70*i);
		w.draw(tex[i]);
	}
//	w.draw(puntuaciones);
	w.draw(presiona_start);
}
