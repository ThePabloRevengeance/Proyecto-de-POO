#ifndef ESCENAPUNTAJES_H
#define ESCENAPUNTAJES_H
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include <fstream>
#include <vector>
using namespace sf;
class EscenaPuntajes : public EscenaBase {
	sf::Text mejores_puntajes, presiona_start,puntuaciones;
	Font fuente_texto;
	ifstream archivo;
	vector<string>v;
public:
	EscenaPuntajes();
	void procesar_eventos(RenderWindow &w) override;
	void actualizar() override;
	void dibujar(RenderWindow &w) override;
};
#endif
