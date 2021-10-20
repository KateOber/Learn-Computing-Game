// ComputingFundamentals.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    VideoMode vm (1920, 1080);
    RenderWindow window(vm, "CSIS4495 Project", Style::Fullscreen);

    Texture firstScreenTexture;
    Sprite firstScreenSprite;
    firstScreenTexture.loadFromFile("Assets/Graphics/first-screen.png");
    firstScreenSprite.setTexture(firstScreenTexture);
    firstScreenSprite.setPosition(0, 0);

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        window.clear();
        window.draw(firstScreenSprite);
        window.display();
    }

    return 0;
}

