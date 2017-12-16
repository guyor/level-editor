#pragma once
#include "Icons.h"

class Erase : public Icons
{
public:
	Erase() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(801 / boardsize.y, 601 / boardsize.x));
		pTexture.loadFromFile("erase.png");
		rect.setTexture(&pTexture);
		rect.setPosition(0, 5 * (601 / boardsize.x));
		window.draw(rect);
	}

};