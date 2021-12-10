// ComputingFundamentals.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <SFML/Graphics.hpp>
#include "PC_Build_Component.h"

using namespace sf;

int main()
{
    VideoMode vm (1920, 1080);
    RenderWindow window(vm, "CSIS4495 Project", Style::Fullscreen);

    Texture firstScreenTexture, startBtnTexture;
    Sprite firstScreenSprite, startBtnSprite;
    Text instructText;
    Font font8bit;

    font8bit.loadFromFile("Assets/Fonts/8bitOperatorPlus8-Bold.ttf");

    firstScreenTexture.loadFromFile("Assets/Graphics/first-screen.png");
    firstScreenSprite.setTexture(firstScreenTexture);
    firstScreenSprite.setPosition(0, 0);

    startBtnTexture.loadFromFile("Assets/Graphics/start.jpg");
    startBtnSprite.setTexture(startBtnTexture);
    startBtnSprite.setPosition(300, 300);

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

        /*
        * 
        Build PC class
        *
        */
       
        Texture towerSideTexture, towerProfileTexture, arrowTexture;
        Sprite arrowSprite;
        towerSideTexture.loadFromFile("Assets/Graphics/tower-profile.png");
        towerProfileTexture.loadFromFile("Assets/Graphics/tower-side.png");
        arrowTexture.loadFromFile("Assets/Graphics/arrow.png");
        
        //using the PC_COMPONENT object
        PC_Build_Component basicTower(towerProfileTexture, towerSideTexture, "Basic Tower");
        basicTower.setScale(Vector2f(0.6, 0.6));
        basicTower.setPosition(Vector2f(800, 300));
        towerSideTexture.loadFromFile("Assets/Graphics/tower-corsair-profile.png");
        towerProfileTexture.loadFromFile("Assets/Graphics/tower-corsair-side.png");
        PC_Build_Component corsairTower(towerProfileTexture, towerSideTexture, "Corsair iCUE 220T RGBM Mid-Tower", "Airflow ATX Computer Case - White", 140, 7);
        corsairTower.setScale(Vector2f(0.3, 0.3));
        corsairTower.setPosition(Vector2f(10, 500));

        //button
        RectangleShape backButton;
        backButton.setSize(Vector2f(192, 79));
        backButton.setFillColor(Color::Color(46, 45, 42));
        backButton.setPosition(0, 0);
        Text backButtonText;
        backButtonText.setFont(font8bit);
        backButtonText.setCharacterSize(30);
        backButtonText.setFillColor(Color::White);
        backButtonText.setString("Back");
        textRect = backButtonText.getLocalBounds();
        backButtonText.setOrigin(textRect.left + textRect.width / 2.0f,
            textRect.top + textRect.height / 2.0f);
        backButtonText.setPosition(backButton.getLocalBounds().width / 2.0f, backButton.getLocalBounds().height/2.0f);
        //side bar
        RectangleShape sideBar;
        sideBar.setSize(Vector2f(300, 1080));
        sideBar.setFillColor(Color::Color(79, 77, 71));
        sideBar.setPosition(0, 0);
        //Arrow
        arrowSprite.setTexture(arrowTexture);
        arrowSprite.setScale(0.9, 0.9);
        arrowSprite.setPosition(1400, 800);

        bool side = false;

    /* */

    bool startScreen = true;
    bool mainScreen = false;

    bool paused = false;
    bool acceptingInput = true;

    while (window.isOpen()) {

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::MouseButtonReleased && !paused)
            {
                // Listen for button presses
                acceptingInput = true;
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        //START SCREEN
        if (startScreen && !mainScreen) {
            window.clear();
            window.draw(firstScreenSprite);
            window.draw(startBtnSprite);
            window.draw(instructText);
            window.display();
            if (acceptingInput) {
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    if (Mouse::getPosition().y < 500) {
                        acceptingInput = false;
                        //to get position relative to the window
                        Vector2i mousePos = Mouse::getPosition(window);
                        //safe cast (float) unsafe
                        static_cast<float>(mousePos.y);
                        startScreen = false;
                        mainScreen = true;

                    }
                }
            }
        }
        //MAIN SCREEN
        if (!startScreen && mainScreen) {
            window.clear();
            shapes[3].setFillColor(Color::Blue);
            for (int i = 0; i < 4; i++) {
                window.draw(shapes[i]);
                window.draw(gameModesText[i]);
            }

            window.display();
            if (acceptingInput) {
                if (Mouse::isButtonPressed(Mouse::Left)) {

                    if (Mouse::getPosition().y < shapes[3].getGlobalBounds().top + 230 && Mouse::getPosition().y > shapes[3].getGlobalBounds().top) {
                        acceptingInput = false;
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
        }
       //GAME MODE
       if (!startScreen && !mainScreen) {
            window.clear();
            instructText.setString("This is a free play mode"); 
            instructText.setPosition(1920 / 2, 100);
            window.draw(sideBar);          
            window.draw(instructText);
            if (side) {
            window.draw(basicTower.getSideSprite());
            }
            else {
            window.draw(basicTower.getFrontSprite()); 
            }
            window.draw(backButton);
            window.draw(backButtonText);
            window.draw(arrowSprite);
            window.draw(corsairTower.getFrontSprite());
            window.display();

            if (acceptingInput) {
                if (Mouse::isButtonPressed(Mouse::Left)) {
                    //back button
                    if (Mouse::getPosition().x < 192 && Mouse::getPosition().y < 79) {
                        mainScreen = true;
                        acceptingInput = false;
                    }
                    //arrow
                    textRect = arrowSprite.getLocalBounds();
                    if ((Mouse::getPosition().x < (arrowSprite.getPosition().x + textRect.width) && Mouse::getPosition().y < (arrowSprite.getPosition().x + textRect.height))){
                        if (!side)
                            side = true;
                        else
                            side = false;
                    }
                }
            }

        }
    }
    
    
    

    return 0;
}
void StartScreen() {

}
void MainScreen() {

}
void FreePlayMode() {

}

