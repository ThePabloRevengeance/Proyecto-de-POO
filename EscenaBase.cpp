#include "EscenaBase.h"
#include "Entidad.h"
#include <SFML/Window/Event.hpp>


EscenaBase::EscenaBase(){
	
}

void EscenaBase::actualizar(){
	for(size_t i=0;i<entidades.size();i++){
		entidades[i]->actualizar();
	}
	
}
void EscenaBase::dibujar(RenderWindow &w){
	for(size_t i=0;i<entidades.size();i++){
		entidades[i]->dibujar(w);
	}
}
void EscenaBase::procesar_eventos(RenderWindow &w){
//	Event e;
//	while(w.pollEvent(e)) {
//		if(e.type == e.Closed) w.close();
//		else{
//			procesar_evento_singular(e);
//		}
//	}
}
//void EscenaBase::procesar_evento_singular(const sf::Event &e){
//	
//}
void EscenaBase::agregar_entidad(Entidad *e){
	entidades.push_back(e);
}
void EscenaBase::limpiar_entidades(){
	entidades.clear();
}
