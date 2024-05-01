#include <SFML/Graphics.hpp>
#include <iostream>
#include "Button.h"


int main()
{
    sf::RenderWindow window(sf::VideoMode().getDesktopMode(), "SFML_BUTTON");
    window.setFramerateLimit(60);
    Button but(sf::VideoMode().getDesktopMode().width  / 2, 
        sf::VideoMode().getDesktopMode().height / 2, 
        sf::VideoMode().getDesktopMode().width / 10, 
        sf::VideoMode().getDesktopMode().width / 10);

    sf::FloatRect buttonBounds = but.getButton().getGlobalBounds();
    while (window.isOpen()) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (but.onPressed(sf::Mouse::getPosition(window))) {
                        std::cout << "SHOOOOOM" << std::endl;
                    }
                }
            }
        }
        if (buttonBounds.contains(static_cast<sf::Vector2f>(mousePos))) {
            but.getButton().setFillColor(sf::Color::Red);
        }
        else {
            but.getButton().setFillColor(sf::Color::White);
        }
        window.clear();
        but.draw(window);
        window.display();

    }
    


    return 0;
}