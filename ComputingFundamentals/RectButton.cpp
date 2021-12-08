#include "RectButton.h"
#include <SFML/Graphics.hpp>
using namespace sf;
RectButton::RectButton() {
	size = Vector2f(0, 0);
}
RectButton::RectButton(Color c, Vector2f pos, Vector2f s, Text t){
	color = c; position = pos; this->size = s; text = t;
	this->shape.setFillColor(color);
	this->shape.setSize(s);
	this->shape.setPosition(pos);
	this->fR = text.getLocalBounds();
	text.setOrigin(fR.left + fR.width / 2.0f,
		fR.top + fR.height / 2.0f);
	text.setPosition(pos.x+s.x/ 2, pos.y+s.y / 2);
}