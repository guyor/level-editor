#pragma once
#include "Icons.h"

class Wall : public Icons
{
public:
	Wall() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(80, 60));
		pTexture.loadFromFile("wall.png");
		rect.setTexture(&pTexture);
		rect.setPosition(3 * 80, 0);
		window.draw(rect);
	}

};