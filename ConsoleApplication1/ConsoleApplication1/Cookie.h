#pragma once
#include "Toolbar.h"

class Cookie : public Toolbar
{
public:
	Cookie() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		m_sprite[COOKIE].setPosition(COOKIE * P_SIZE, 0);
		window.draw(m_sprite[COOKIE]);
	}

};