#ifndef ESCENAMENU_H
#define ESCENAMENU_H
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "EscenaBase.h"
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>
using namespace sf;
class EscenaMenu : public EscenaBase {
	sf::Text titulo, titulo2, presiona_start, presiona_i;
	sf::Font fuente_titulo;
	Clock c;
	Time t;
//	int i=0;
public:
	EscenaMenu();
	void procesar_eventos(RenderWindow &w) override;
	void actualizar() override;
	void dibujar(RenderWindow &w) override;
};
#endif
