#pragma once
#include "Icons.h"

class Demon : public Icons
{
public:
	Demon() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(801 / boardsize.y, 601 / boardsize.x));
		pTexture.loadFromFile("demon.png");
		rect.setTexture(&pTexture);
		rect.setPosition(801 / boardsize.y, 0);
		window.draw(rect);
	}

};