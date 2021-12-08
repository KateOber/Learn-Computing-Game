#include "Button.h"
#include <SFML/Graphics.hpp>
using namespace sf;

Button::Button(Texture tTure, Vector2f bStart, Text txt) {
	this->texture = tTure;
	setWidget(bStart, texture);
}
void Button::setWidget(Vector2f bStart, Texture t) {
	sprite.setTexture(t);
	sprite.setPosition(bStart);
}
bool Button::isButtonClicked() {
	Vector2i mPos = Mouse::getPosition();
	if (sprite.getGlobalBounds().contains(mPos.x, mPos.y)) {
		return true;
	}
	return false;
}