#pragma once
#include "Icons.h"

class Save : public Icons
{
public:
	Save() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(801 / boardsize.y, 601 / boardsize.x));
		pTexture.loadFromFile("save.png");
		rect.setTexture(&pTexture);
		rect.setPosition(0, 4 * (601 / boardsize.x));
		window.draw(rect);
	}

};