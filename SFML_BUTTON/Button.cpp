#include "Button.h"

Button::Button(float x, float y, float width, float height)
{
	button.setPosition(x - (width / 2), y - (height / 2));
	button.setSize(sf::Vector2f(width,height));
	button.setFillColor(sf::Color(50,50,50,200));
}

void Button::draw(sf::RenderWindow& window)
{
	window.draw(this->button);
}

bool Button::onPressed(sf::Vector2i mousePos)
{
	if (mousePos.x >= button.getPosition().x &&
		mousePos.x <= button.getPosition().x + button.getSize().x &&
		mousePos.y >= button.getPosition().y &&
		mousePos.y <= button.getPosition().y + button.getSize().y) {
		return true;
	}
	return false;
}
