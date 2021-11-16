#ifndef ESCENAINSTRUCCIONES_H
#define ESCENAINSTRUCCIONES_H
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace sf;
class EscenaInstrucciones : public EscenaBase {
	sf::Text mover_izq, mover_der, descender_rapido,rotar_luces, rotar_luces2, volver,continuar, juntar_luces, juntar_luces2, juntar_luces3, objetivo,objetivo2;
	sf::Font fuente;
	Texture t1,t2,t3,t4;
	Sprite s1,s2,s3,s4;
	
	int pagina;
//	Clock c;
//	Time t;
	//	int i=0;
public:
	EscenaInstrucciones();
	void procesar_eventos(RenderWindow &w) override;
	void actualizar() override;
	void dibujar(RenderWindow &w) override;
};
#endif
