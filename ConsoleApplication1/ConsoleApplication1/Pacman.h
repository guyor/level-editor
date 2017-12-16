#pragma once

#include "Icons.h"
#include <iostream>

class Pacman : public Icons
{
public:

	Pacman() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		sf::Texture pTexture;
		sf::RectangleShape rect(sf::Vector2f(801/boardsize.y,601/boardsize.x));
		pTexture.loadFromFile("pacman.png");
		rect.setTexture(& pTexture);
		window.draw(rect);
	}

private:


};