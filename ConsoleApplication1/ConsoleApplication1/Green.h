#pragma once
#include "Toolbar.h"

class Green : public Toolbar
{
public:
	Green() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		m_sprite[GREEN].setPosition(GREEN * P_SIZE, 0);
		window.draw(m_sprite[GREEN]);
	}

};