#include "terna.h"
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include <iostream>

using namespace sf;
using namespace std;
terna::terna(){
	for(int i=0;i<3;i++){
		int c=rand()%6+1;
		m_x[i]=2;
		m_y[i]=(-3)+i;
		colores[i]=c;
	}
}
void terna::intercambiar(){
	int auxiliar=colores[2];
	colores[2]=colores[1];
	colores[1]=colores[0];
	colores[0]=auxiliar;
//	int auxiliar=colores[0];
//	colores[0]=colores[1];
//	colores[1]=colores[2];
//	colores[2]=auxiliar;
}
void terna::caer(int b){
	for(int i=0;i<3;i++){
		m_y[i]=m_y[i]+b;
	}
}
void terna::movimiento_lateral(int b){
	for(int i=0;i<3;i++){
		m_x[i]=m_x[i]+b;
	}
}
int terna::ver_Y(int a){
	return m_y[a];
}
int terna::ver_X(int b){
	return m_x[b];
}
int terna::ver_color(int a){
	return colores[a];
}
void terna::actualizar(){
	
}
void terna::dibujar(RenderWindow &w){
	
}

