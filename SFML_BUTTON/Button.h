#pragma once

#include <SFML/Graphics.hpp>
class Button {
	sf::RectangleShape button;
	sf::Texture buttonTexture;

public:
	Button(
		float,
		float,
		float,
		float
	);
	void draw(sf::RenderWindow&);
	bool onPressed(sf::Vector2i);
	sf::RectangleShape getButton() {
		return button;
	}
};