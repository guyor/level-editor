#pragma once
#include "Icons.h"

class Cookie : public Icons
{
public:
	Cookie() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(801 / boardsize.y, 601 / boardsize.x));
		pTexture.loadFromFile("cookie.png");
		rect.setTexture(&pTexture);
		rect.setPosition(2 * (801 / boardsize.y),0);
		window.draw(rect);
	}

};