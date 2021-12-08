#pragma once
#define RECTBUTTON_H
#include <SFML/Graphics.hpp>
using namespace sf;
class RectButton
{
public:
	RectButton();
	RectButton(Color c, Vector2f pos, Vector2f size, Text t);
	Text text;
	Color color;
	Vector2f position;
	Vector2f size;
	RectangleShape shape;
private:
	FloatRect fR;
};

