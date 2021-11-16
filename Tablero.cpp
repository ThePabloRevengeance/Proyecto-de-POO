#include "Tablero.h"
#include <iostream>
#include <vector>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
using namespace std;

Tablero::Tablero(){
	v.push_back(t);
	tex.loadFromFile("luz5.png");
	s.setTexture(tex);
	
	
}


bool Tablero::chequear(/*int estado*/){
//	estado_actual=estado;
	bool hubo_match=false;
	int cant_luces;
    ///// VERIFICA VERTICALMENTE SI SE PRODUCE UN MATCH
	for(int j=0;j<6;j++){
		for(int i=0;i<12;i++){
			////PREGUNTA SI SE PRODUCE UN MATCH DE A 5
			if(m[i][j]!=0 && m[i][j]==m[i+1][j] && m[i][j]==m[i+2][j] && m[i][j]==m[i+3][j] && m[i][j]==m[i+4][j]){
				for(int k=i;k<i+5;k++){
					fila.push_back(k);
					columna.push_back(j);
				}
				hubo_match=true;
				return hubo_match;
			}
			////SINO, PREGUNTA SI SE PRODUCE UN MATCH DE A 4
			else if(m[i][j]!=0 && m[i][j]==m[i+1][j] && m[i][j]==m[i+2][j] && m[i][j]==m[i+3][j]){
				for(int k=i;k<(i+4);k++){
					fila.push_back(k);
					columna.push_back(j);
				}
				hubo_match=true;
				return hubo_match;
			}
			////SI TAMPOCO SE PRODUCE UN MATCH DE A 4, PREGUNTA SI SE PRODUCE UN MATCH DE 3
			else if(m[i][j]!=0 && m[i][j]==m[i+1][j] && m[i][j]==m[i+2][j]){
				for(int k=i;k<i+3;k++){
					fila.push_back(k);
					columna.push_back(j);
				}
				hubo_match=true;
				return hubo_match;
			}
		}
	}
	
	
	///// VERIFICA HORIZONTALMENTE SI SE PRODUCE UN MATCH
	for(int j=0;j<4;j++){
		for(int i=0;i<14;i++){
			////PREGUNTA SI SE PRODUCE UN MATCH DE A 5
			if(m[i][j]!=0 && m[i][j]==m[i][j+1] && m[i][j]==m[i][j+2] && m[i][j]==m[i][j+3] && m[i][j]==m[i][j+4]){
				for(int k=j;k<j+5;k++){
					if(fila.size()<6){
						fila.push_back(i);
						columna.push_back(k);
					}
					
				}
				hubo_match=true;
				return hubo_match;
			}
			////SINO, PREGUNTA SI SE PRODUCE UN MATCH DE A 4
			else if(m[i][j]!=0 && m[i][j]==m[i][j+1] && m[i][j]==m[i][j+2] && m[i][j]==m[i][j+3]){
				for(int k=j;k<j+4;k++){
					if(fila.size()<5){
						fila.push_back(i);
						columna.push_back(k);
					}
				}
				hubo_match=true;
				return hubo_match;
			}
			////SI TAMPOCO SE PRODUCE UN MATCH DE A 4, PREGUNTA SI SE PRODUCE UN MATCH DE 3
			else if (m[i][j]!=0 && m[i][j]==m[i][j+1] && m[i][j]==m[i][j+2]){
				for(int k=j;k<j+3;k++){
					if(fila.size()<4){
						fila.push_back(i);
						columna.push_back(k);
					}
				}
				hubo_match=true;
				return hubo_match;
			}
		}
	}
	/*cout<<fila.size()<<"--"<<columna.size()<<endl;*/
	return hubo_match;
}



/////PRODUZCO EL MATCH Y HAGO DESAPARECER LAS LUCES QUE LO FORMAN
void Tablero::match(){
	for(int i=0;i<fila.size();i++){
		m[fila[i]][columna[i]]=0;
		
	}
//	for(int i=0;i<fila.size();i++){
//		cout<<fila[i]<<"--"<<columna[i]<<endl;
//	}
}




void Tablero::bajar_luces(){
	/////SI LAS COLUMNAS SON IGUALES, ES PORQUE SE PRODUJO UN MATCH VERTICAL
	int a=fila.size();
	if(columna[0]==columna[1]){
	 for(int i=fila[0]-1;i>0;i--){
		m[i+a][columna[0]]=m[i][columna[1]];
	 }
	 for(int i=fila[0]-1;i>-1;i--){
		 m[i][columna[0]]=0;
	 }
	}
	/////SI LAS FILAS SON IGUALES, ES PORQUE SE PRODUJO UN MATCH HORIZONTAL
	else if(fila[0]==fila[1]){ 
		for(int j=columna[0];j<columna[0]+a;j++){
			for(int i=fila[0]-1;i>0;i--){
				m[i+1][j]=m[i][j];
			}
		}
		
	}
	fila.clear();
	columna.clear();
//	estado_actual=1;
}


bool Tablero::no_puede_crear_terna(){
	int luces=0;
	for(int i=0;i<12;i++){
		if(m[i][2]!=0){
			luces++;
		}
	}
	if(m[0][2]!=0){
		return true;
	}else{
		
		return false;
	}
}

/////DEVUELVE LA TERNA SI LA NECESITO EN EL CICLO INICIAL
terna &Tablero::get_terna(){
	return *v[0];
}




void Tablero::actualizar(){
	////MUESTRO LA MATRIZ POR CONSOLA
// cout<<"Tablero:"<<endl;
//	for(int i=0;i<14;i++){
//		for(int j=0;j<6;j++){
//			cout<<m[i][j];
//		}
//		cout<<endl;
//	}
	
	////SI LA TERNA NO PUEDE CAER, FIJA LA TERNA Y CREA UNA NUEVA
	if(ternapuedecaer()){///
		v[0]->caer(1);
	}else{
		fijarterna();
//		nueva_terna();
	}
		//////IGUALO A 0 LAS POSICIONES QUE ESTAN ARRIBA DE LA TERNA 
	for(int i=v[0]->ver_Y(0)-1;i>-1;i--){
		m[i][v[0]->ver_X(0)]=0;  /////
	}
}








int &Tablero::get_textura(){
	return a;
}

vector<int> &Tablero::get_filas(){
	return fila;
}
void Tablero::dibujar(RenderWindow &w){
	for(int r=0;r<3;r++){
		////ASIGNO LOS COLORES DE LAS LUCES A LAS POSICIONES DE LA MATRIZ DONDE SE ENCUENTRA LA TERNA
		if(v[0]->ver_Y(r)>=0){
			m[v[0]->ver_Y(r)][v[0]->ver_X(r)]=v[0]->ver_color(r);
		}
		
	}
	
	for(int i=0;i<14;i++){
		for(int j=0;j<6;j++){
			/////SI EN ESA POSICION DE LA MATRIZ NO HAY UN CERO, QUE DIBUJE LA LUZ CON SU COLOR CORRESPONDIENTE
			if(m[i][j]!=0){
				s.setTextureRect(IntRect(50,m[i][j]*50,50,50));
				s.setPosition(j*50+10,i*50+10);
				w.draw(s);
			}
		}
		
		/////DIBUJADO DEL MATCH, CAMBIANDO LA VARIABLE A PARA DESPLAZARSE EN LA TEXTURA DEL SPRITE
		for(int l=0;l<fila.size();l++){
			/*cout<<"Fila:"<<fila[l]<<" "<<"columna:"<<columna[l]<<endl;*/
			s.setTextureRect(IntRect(50*a,m[fila[l]][columna[l]]*50,50,50));
			s.setPosition(columna[l]*50+10,fila[l]*50+10);
			w.draw(s);	
		}
	}
	
}

void Tablero::pasar_estado(int i){
	estado_actual=i;
}




bool Tablero::ternapuedecaer(){
	int i=v[0]->ver_Y(2);
	int j=v[0]->ver_X(2);
	if(m[i+1][j]==0 && i<13 && estado_actual==1){  ////SI ABAJO HAY UN CERO, DEVUELVE VERDADERO
		return true;
	}else{
		return false;
	}
}












////DEJO DE TRABAJAR CON LA ACTUAL TERNA Y CREO UNA NUEVA
void Tablero::fijarterna(){
	v.clear();
	
}



void Tablero::nueva_terna(){
	terna *t=new terna();
	v.push_back(t);
}








void Tablero::terna_moverizq(){
	////SI X ES MAYOR A 0 O A LA IZQUIERDA HAY UN CERO, SE MUEVE A LA IZQ
	if(v[0]->ver_X(2)>0 && m[v[0]->ver_Y(2)][v[0]->ver_X(2)-1]==0){ 
		v[0]->movimiento_lateral(-1); 
		//////Y LAS FILAS EN LA QUE LA TERNA SE ENCONTRABA EN LA COLUMNA ANTERIOR SE IGUALAN A 0
		for(int r=0;r<3;r++){
			/*m[v[0]->ver_Y(r)][v[0]->ver_X(r)]=v[0]->ver_color(r);*/
			m[v[0]->ver_Y(r)][v[0]->ver_X(r)+1]=0;
		}
	}
}















void Tablero::terna_moverder(){
	////SI X ES MENOR A 5 O A LA DERECHA HAY UN CERO, SE MUEVE A LA DERECHA
	if(v[0]->ver_X(2)<5 && m[v[0]->ver_Y(2)][v[0]->ver_X(2)+1]==0){
		v[0]->movimiento_lateral(1);
		//////Y LAS FILAS EN LA QUE LA TERNA SE ENCONTRABA EN LA COLUMNA ANTERIOR SE IGUALAN A 0
		for(int r=0;r<3;r++){
			/*m[v[0]->ver_Y(r)][v[0]->ver_X(r)]=v[0]->ver_color(r);*/
			m[v[0]->ver_Y(r)][v[0]->ver_X(r)-1]=0;
		}
	}
	
}

	

