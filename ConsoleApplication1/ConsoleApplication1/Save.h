#pragma once
#include "Icons.h"

class Save : public Icons
{
public:
	Save() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(80, 60));
		pTexture.loadFromFile("save.png");
		rect.setTexture(&pTexture);
		rect.setPosition(4 * 80, 0);
		window.draw(rect);
	}

};