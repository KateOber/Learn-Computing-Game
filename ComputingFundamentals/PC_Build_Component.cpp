#include "PC_Build_Component.h"

PC_Build_Component::PC_Build_Component(Texture sideView, Texture frontView, String name) {

	m_sideViewTexture = sideView;
	m_frontViewTexture = frontView;
	m_name = name;

	setTextures();
}
PC_Build_Component::PC_Build_Component(Texture sideView, Texture frontView, String name, String details, float price, int performancee) {

	m_sideViewTexture = sideView;
	m_frontViewTexture = frontView;
	m_name = name;
	m_details = details;
	m_price = price;
	m_performance = performancee;

	setTextures();
}
 void PC_Build_Component::setDetails(String details) {
	m_details = details;
}
 //setters
 void setDetails();
 void setBackView(Texture backView);
 void setPosition(Vector2f position);
 //getters
 FloatRect PC_Build_Component::getPosition() {
	 return m_sideViewSprite.getLocalBounds();
 }
 float getPrice();
 int getPerformance();
 String getDetails();
 String getName();
 Sprite PC_Build_Component::getSideSprite(){
	 return m_sideViewSprite;
 }
 Sprite PC_Build_Component::getFrontSprite(){
	 return m_frontViewSprite;
 }

 //add check if texutre avalibable
 void PC_Build_Component::setTextures() {

	 m_sideViewSprite.setTexture(m_sideViewTexture);
	 m_frontViewSprite.setTexture(m_frontViewTexture);
 }
 void PC_Build_Component::setScale(Vector2f scale) {
	 m_scale = scale;
	 m_sideViewSprite.setScale(m_scale);
	 m_frontViewSprite.setScale(m_scale);
 }
 Vector2f PC_Build_Component::getScale() {
	 return m_scale;
 }
 void PC_Build_Component::setPosition(Vector2f position) {
	 m_sideViewSprite.setPosition(position);
	 m_frontViewSprite.setPosition(position);
 }


