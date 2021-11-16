#ifndef TERNA_H
#define TERNA_H

#include <SFML/Window/Event.hpp>
#include <vector>
#include "Entidad.h"
using namespace std;
using namespace sf;

class terna:public Entidad{
	int m_x[3];
	int m_y[3];
	int colores[3];
public:
	terna();
	void intercambiar();
	void movimiento_lateral(int b);
	void caer(int b);
	int ver_Y(int a);
	int ver_X(int b);
	int ver_color(int a);
	void actualizar()override;
	void dibujar(RenderWindow &w)override;
};
#endif
