#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
class Animation
{
public:
	Animation(Texture* texture, Vector2u numOfImage, float switchTime);

	void Update(int row, float dt);

public: IntRect uvRect;
private:
	Vector2u imageCount;
};

