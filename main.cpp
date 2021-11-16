#include <SFML/Graphics.hpp>
//#include <SFML/Window/VideoMode.hpp>
#include <iostream>
#include <iomanip>
#include "Juego.h"
#include "EscenaMenu.h"


using namespace sf;

int main(int argc, char *argv[]){
	Juego &j=j.crear(VideoMode(800,720), new EscenaMenu(), "Proyecto de POO 2018");
	j.run();
	return 0;
}

