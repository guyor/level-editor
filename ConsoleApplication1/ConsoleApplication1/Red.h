#pragma once
#include "Toolbar.h"

class Red : public Toolbar
{
public:
	Red() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(80, 60));
		pTexture.loadFromFile("red.png");
		rect.setTexture(&pTexture);
		rect.setPosition(7 * 80, 0);
		window.draw(rect);
	}

};