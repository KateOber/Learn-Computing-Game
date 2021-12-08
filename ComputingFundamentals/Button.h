#ifndef BUTTON_H
#define BUTTON_H
#include <SFML/Graphics.hpp>
using namespace sf;

class Button {
public:
	Button(Texture tTure, Vector2f bStart, Text txt);
	Text text;
	void onClicked();
	bool isButtonClicked();
	Sprite sprite;

private:
	//This is so you can pass a specific void function by reference to the Button
	Texture texture;

	void setWidget(Vector2f startPoint, Texture t);
};

#endif
