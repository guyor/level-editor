#pragma once
#include "Icons.h"

class Clear : public Icons
{
public:
	Clear() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(801 / boardsize.y, 601 / boardsize.x));
		pTexture.loadFromFile("clear.png");
		rect.setTexture(&pTexture);
		rect.setPosition(0, 6 * (601 / boardsize.x));
		window.draw(rect);
	}


};