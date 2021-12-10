#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

//Class used to initialize each component for the PC Building Mode 
class PC_Build_Component
{
private:
	String m_name;
	String m_details;
	float m_price;
	//0-10 (add enum in the future)
	int m_performance;
	bool m_isUnlocked;
	bool m_isUsed;

	//visual
	Texture m_sideViewTexture, m_frontViewTexture, m_backViewTexture;
	Sprite m_sideViewSprite, m_frontViewSprite, m_backViewSprite;
	Vector2f m_position;
	IntRect m_imageSize;
	Vector2f m_scale;
	//inside Texure set
	void setTextures();

public:
	//Constructors depending on level of details
	PC_Build_Component(Texture sideView, String name);
	PC_Build_Component(Texture sideView, Texture frontView, String name);
	PC_Build_Component(Texture sideView, Texture frontView, String name, String details);
	PC_Build_Component(Texture sideView, Texture frontView, String name, String details, float price, int performance);
	//setters
	void setDetails(String details);
	void setBackView(Texture backView);
	void setPosition(Vector2f position);
	void setScale(Vector2f scale);
	//getters
	FloatRect getPosition();
	float getPrice();
	int getPerformance();
	String getDetails();
	String getName();
	Vector2f getScale();
	//not the best approach find a better way to return the object sprite
	Sprite getSideSprite();
	Sprite getFrontSprite();
};

