#pragma once
#include "Toolbar.h"

class Blue : public Toolbar
{
public:
	Blue() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(80,60));
		pTexture.loadFromFile("blue.png");
		rect.setTexture(&pTexture);
		rect.setPosition(9 * 80, 0);
		window.draw(rect);
	}

};
