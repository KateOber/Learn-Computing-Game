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
    Text gameModesText[4];
    for (int i = 0; i < 4; i++) {
        gameModesText[i].setFont(font8bit);
        gameModesText[i].setCharacterSize(70);
        gameModesText[i].setFillColor(Color::White);
    }
    gameModesText[0].setString("DISCOVER");
    gameModesText[1].setString("LOGIC GATES AND BINARY");
    gameModesText[2].setString("BUILD A PC");
    gameModesText[3].setString("FREE PLAY");
    /*Move to class later*/

    for (int i = 0; i < 4; i++) {
        shapes[i].setSize(Vector2f(1800, 230));
        shapes[i].setFillColor(Color::Blue);
        shapes[i].setPosition(position);


        FloatRect textRect = gameModesText[i].getLocalBounds();
        gameModesText[i].setOrigin(textRect.left + textRect.width / 2.0f,
            textRect.top + textRect.height / 2.0f);
        gameModesText[i].setPosition(1920/2, position.y+230/2);

        position += Vector2f(0, 260);
    }
        instructText.setFont(font8bit);
        instructText.setCharacterSize(50);
        instructText.setFillColor(Color::Blue);
        instructText.setString("Click \"Start\" to begin\n    Press ESC to Exit");
        FloatRect textRect = instructText.getLocalBounds();
        instructText.setOrigin(textRect.left + textRect.width / 2.0f,
            textRect.top + textRect.height / 2.0f);
        instructText.setPosition(300 + (textRect.left + startBtnSprite.getLocalBounds().width / 2.0f) , 200);

    /* */

    bool startScreen = true;
    bool mainScreen = false;

    while (window.isOpen()) {
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        if (startScreen && !mainScreen) {
            window.clear();
            window.draw(firstScreenSprite);
            window.draw(startBtnSprite);
            window.draw(instructText);
            window.display();
            if (Mouse::isButtonPressed(Mouse::Left)) {
                if (Mouse::getPosition().y < 500) {
                    //to get position relative to the window
                    Vector2i mousePos = Mouse::getPosition(window);
                    //safe cast (float) unsafe
                    static_cast<float>(mousePos.y);
                    startScreen = false;
                    mainScreen = true;
                    window.clear();
                    // window.draw(testSprite);
                    // window.draw(electron);
                    for (int i = 0; i < 4; i++) {
                        window.draw(shapes[i]);
                        window.draw(gameModesText[i]);
                    }

                    window.display();
                }
            }
        }

        if (!startScreen && mainScreen) {
            if (Mouse::isButtonPressed(Mouse::Left)) {

                if (Mouse::getPosition().y < shapes[3].getGlobalBounds().top + 230 && Mouse::getPosition().y > shapes[3].getGlobalBounds().top) {
                   
                    window.clear();
                    for (int i = 0; i < 3; i++) {
                        window.draw(shapes[i]);
                        window.draw(gameModesText[i]);
                    }

                    shapes[3].setFillColor(Color::Cyan);
                    window.draw(shapes[3]);
                    window.draw(gameModesText[3]);
                    window.display();
                    sleep(milliseconds(300));
                    mainScreen = false;
                }
            }
        }
       if (!startScreen && !mainScreen) {
            window.clear();
            instructText.setString("This is a free play mode");            
            window.draw(instructText);
            window.display();
        }
    }
    
    
    

    return 0;
}

