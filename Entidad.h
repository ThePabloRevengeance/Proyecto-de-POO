#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <SFML/Graphics/RenderWindow.hpp>
class Entidad{
public:
	virtual void actualizar()=0;
	virtual void dibujar(sf::RenderWindow &w)=0;
};
#endif
