#ifndef ESCENABASE_H
#define ESCENABASE_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <vector>
#include "Entidad.h"
using namespace std;
using namespace sf;
class EscenaBase{
private:
	vector<Entidad*>entidades;
public:
	EscenaBase();
	virtual void actualizar();
	virtual void dibujar(RenderWindow &w);
	virtual void procesar_eventos(RenderWindow &w);
	/*virtual void procesar_evento_singular(const sf::Event &e);*/
	void agregar_entidad(Entidad *e);
	void limpiar_entidades();
	
};
#endif
