#pragma once
#include "Toolbar.h"

class Wall : public Toolbar
{
public:
	Wall() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		m_sprite[WALL].setPosition(WALL * P_SIZE, 0);
		window.draw(m_sprite[WALL]);
	}

};