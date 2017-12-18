#pragma once
#include "Icons.h"

class Erase : public Icons
{
public:
	Erase() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(80, 60));
		pTexture.loadFromFile("erase.png");
		rect.setTexture(&pTexture);
		rect.setPosition(5 * 80, 0);
		window.draw(rect);
	}

};