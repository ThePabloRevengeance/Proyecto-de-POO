#ifndef TABLERO_H
#define TABLERO_H
#include "Entidad.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include "terna.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "luces.h"
using namespace std;
class Tablero:public Entidad{
private:
	int m[14][6]={
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
    {0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,0,0},
	};
	terna *t=new terna();
	/*bool hubo_match=false;*/
	vector<int>columna;
	vector<int>fila;
	vector<terna*>v;
	Texture tex,tex_cartel;
	Sprite s,cartel;
	int a=1;
	int estado_actual=1;
public:
	Tablero();
	terna &get_terna();
	int &get_textura();
	vector<int> &get_filas();
	bool ternapuedecaer();
	bool chequear();
	bool no_puede_crear_terna();
	void pasar_estado(int i);
	void nueva_terna();
	void terna_moverizq();
	void terna_moverder();
	void fijarterna();
	void actualizar() override;
	void dibujar(RenderWindow &w)override ;
	void match();
	void bajar_luces();
};
#endif
