#ifndef ESCENAJUEGO_H
#define ESCENAJUEGO_H
#include "EscenaBase.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>

#include "Tablero.h"
#include "Entidad.h"
#include <fstream>
#include <ios>
#include <list>
#include <vector>
using namespace std;
using namespace sf;

class EscenaJuego: public EscenaBase {
private:
	Clock c;
	Time t;
	bool tecla_I = false;
	bool tecla_D = false;
	bool tecla_A = false;
	bool tecla_S = false;
	bool tecla_P = false;
	bool aceleracion=false;
	int estado, puntos ,nivel, puntaje_nivel, velocidad;
	int estado_gameover=1;
	Tablero *p=new Tablero();
	Sprite fondo,game_over,game_over2;
	Texture tex_fondo,tex_gameover,tex_gameover2;
	Text texto,puntaje,texto_nivel,numero_nivel,continuar,continuar2;
	Font fuente;
	ofstream ahinco;
	
	
	
	
	/*vector<Entidad*>E;*/
public:
	EscenaJuego();
	void pieza_esperando();
//	void agregar_entidad(Entidad *h);
	void actualizar() override;
	void dibujar(RenderWindow &w) override;
	void procesar_eventos(RenderWindow &w) override;
	void ordenar_puntajes();
	
};
#endif
