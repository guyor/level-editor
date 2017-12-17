#pragma once
#include "Icons.h"

class Green : public Icons
{
public:
	Green() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(801 / boardsize.y, 601 / boardsize.x));
		pTexture.loadFromFile("green.png");
		rect.setTexture(&pTexture);
		rect.setPosition(8 * (801 / boardsize.y), 0);
		window.draw(rect);
	}

};