#pragma once

#include "Toolbar.h"
#include <iostream>

class Pacman : public Toolbar
{
public:

	Pacman() : position(0,0) {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		window.draw(m_sprite[PACMAN]);
	}

private:
	sf::Vector2f position;

};