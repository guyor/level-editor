#pragma once

#include "Toolbar.h"
#include <iostream>

class Pacman : public Toolbar
{
public:

	Pacman() : position(0,0) {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(80,60));
		pTexture.loadFromFile("pacman.png");
		rect.setTexture(& pTexture);
		window.draw(rect);
	}

private:
	sf::Vector2f position;

};