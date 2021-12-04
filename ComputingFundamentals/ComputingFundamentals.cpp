// ComputingFundamentals.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    VideoMode vm (1920, 1080);
    RenderWindow window(vm, "CSIS4495 Project", Style::Fullscreen);

    Texture firstScreenTexture, startBtnTexture, testTexture;
    Sprite firstScreenSprite, startBtnSprite, testSprite;
    Text instructText;
    Font font8bit;

    font8bit.loadFromFile("Assets/Fonts/8bitOperatorPlus8-Bold.ttf");

    firstScreenTexture.loadFromFile("Assets/Graphics/first-screen.png");
    firstScreenSprite.setTexture(firstScreenTexture);
    firstScreenSprite.setPosition(0, 0);

    startBtnTexture.loadFromFile("Assets/Graphics/start.jpg");
    startBtnSprite.setTexture(startBtnTexture);
    startBtnSprite.setPosition(300, 300);

  
    testTexture.loadFromFile("Assets/Graphics/background.png");
    testSprite.setTexture(testTexture);
    testSprite.setPosition(0, 0);

    instructText.setFont(font8bit);
    instructText.setCharacterSize(30);
    instructText.setFillColor(Color::Blue);
    instructText.setString("Click \"Start\" to begin\n Press ESC to Exit");
    instructText.setPosition(100, 100);

    /*Move to class later*/
    CircleShape electron(50);
    electron.setFillColor(Color::White);

    //main menu buttons
    RectangleShape shapes[4];
    Vector2f position = Vector2f(50, 10);

    //text for buttons


    for (int i = 0; i < 4; i++) {
        shapes[i].setSize(Vector2f(1800, 230));
        shapes[i].setFillColor(Color::Blue);
        shapes[i].setPosition(position);
        position += Vector2f(0, 260);

        instructText.setFont(font8bit);
        instructText.setCharacterSize(30);
        instructText.setFillColor(Color::Blue);
        instructText.setString("Click \"Start\" to begin\n Press ESC to Exit");
        instructText.setPosition(100, 100);
    }
    /* */

    bool startScreen = true;

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        if (startScreen) {
            window.clear();
            window.draw(firstScreenSprite);
            window.draw(startBtnSprite);
            window.draw(instructText);
            window.display();
        }

        if (Mouse::isButtonPressed(Mouse::Left)) {
            if (Mouse::getPosition().y <500) {
            startScreen = false;
            window.clear();
           // window.draw(testSprite);
           // window.draw(electron);
              for (int i = 0; i < 4; i++) {
                window.draw(shapes[i]);
            }
            window.display();
          
        }
        }
    }

    return 0;
}

