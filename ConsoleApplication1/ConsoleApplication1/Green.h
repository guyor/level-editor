#pragma once
#include "Toolbar.h"

class Green : public Toolbar
{
public:
	Green() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(80, 60));
		pTexture.loadFromFile("green.png");
		rect.setTexture(&pTexture);
		rect.setPosition(8 * 80, 0);
		window.draw(rect);
	}

};