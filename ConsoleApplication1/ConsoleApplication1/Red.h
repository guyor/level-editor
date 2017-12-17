#pragma once
#include "Icons.h"

class Red : public Icons
{
public:
	Red() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(801 / boardsize.y, 601 / boardsize.x));
		pTexture.loadFromFile("red.png");
		rect.setTexture(&pTexture);
		rect.setPosition(7 * (801 / boardsize.y), 0);
		window.draw(rect);
	}

};