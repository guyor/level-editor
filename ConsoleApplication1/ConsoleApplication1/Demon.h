#pragma once
#include "Icons.h"

class Demon : public Icons
{
public:
	Demon() : position(80, 0) {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(80, 60));
		pTexture.loadFromFile("demon.png");
		rect.setTexture(&pTexture);
		rect.setPosition(position);
		window.draw(rect);
	}

private:
	sf::Vector2f position;
};