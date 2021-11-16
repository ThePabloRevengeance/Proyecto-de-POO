
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <SFML/Graphics/Color.hpp>
#include <SFML/System/Vector2.hpp>

//using namespace std;
//using namespace sf;
//luz::luz(Sprite s,Texture t,int color, Vector2f pos){
//	m_s=s;
//	m_t=t;
//	color_num=color;
////	luz_pos=pos;
//	m_s.setTexture(m_t);
//	m_s.setPosition(pos);
//	
///*	rectangulo.setPosition(pos);*/
//	
//	mov_x=0;
//	mov_y=1;
//}
//RectangleShape &luz::GetRectangle(){
//	return rectangulo;
//}
//Sprite &luz::GetSprite(){
//	return m_s;
//}
//bool &luz::GetBool(){
//	return choca;
//}
//int luz::ver_numero(){
//	return color_num;
//}
//void luz::dibujar(RenderWindow &w){
//	w.draw(m_s);
//	w.draw(rectangulo);
//}
//void luz::actualizar(){
//	Vector2f pos=m_s.getPosition();
//	luz_pos=pos;
//	if(mov_y!=0){
//		if(pos.y<670){
//			pos.y+=mov_y;
//			pos.x+=mov_x;
//			if(pos.x>260){
//				pos.x=260;
//			}else if(pos.x<10){
//				pos.x=10;
//			}
//			m_s.setPosition(pos);
//			if(GetBool()==true){
//				
//				rectangulo.setSize(Vector2f(50,50));
//				rectangulo.setPosition(pos);
//				rectangulo.setFillColor(Color::Red);
//				
//				/*w.draw(rectangulo);*/
//			}
//		}
//	}
//	mov_x=0;
//	mov_y=1;
//};
//Vector2f luz::ver_pos(){
//	return luz_pos;
//}
//void luz::mover_x(int i){
//	mov_x=i;
//
//}
//void luz::mover_y(int i){
//	mov_y=i;
//}
//
//bool luz::tocar(const RectangleShape &rec2, sf::Vector2f *out_mtv = nullptr){
//	const FloatRect &recSp1 = m_s.getGlobalBounds();
//	const FloatRect &recSp2 = rec2.getGlobalBounds();
//	float proj_x, proj_y, superpos_x, superpos_y;
//	
//	proj_x = max(recSp1.left + recSp1.width, recSp2.left + recSp2.width) - min(recSp1.left, recSp2.left);
//	if(proj_x < recSp1.width + recSp2.width){
//		
//		if(out_mtv){
//			superpos_x = recSp1.width + recSp2.width - proj_x;
//		}
//		proj_y = max(recSp1.top + recSp1.height, recSp2.top + recSp2.height) - min(recSp1.top, recSp2.top);
//		
//		if(proj_y < recSp1.height + recSp2.height){
//			if(out_mtv){
//				superpos_y = recSp1.height + recSp2.height - proj_y;
//				
//				out_mtv->x = out_mtv->y = 0;
//				if(superpos_x < superpos_y){
//					out_mtv->x = superpos_x * (recSp1.left < recSp2.left?-1:1);
//				}else{
//					out_mtv->y = superpos_y * (recSp1.top < recSp2.top?-1:1);
//				}
//				
//			}
//			return true;
//		}
//	}
//	return false;
//}
//luz::~luz(){};
//
//
//
//
//
//
