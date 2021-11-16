#ifndef JUEGO_H
#define JUEGO_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Texture.hpp>
#include "luces.h"
#include <vector>
#include "terna.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>
#include "Tablero.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "EscenaBase.h"

using namespace sf;
using namespace std;
class Juego {

public:
	static Juego &getJuego();
	static Juego &crear(const VideoMode &videomode, EscenaBase *escena, const string &nombre="");
	void run();
	void cambiar_escena(EscenaBase *escena);
	//	void nueva_terna();
private:
	static Juego *instance;
	Clock c;
	RenderWindow w;
	void procesar_eventos();
	void actualizar();
	void dibujar();
	
	EscenaBase *EscenaActual, *siguienteEscena;
	Juego();
};

#endif

