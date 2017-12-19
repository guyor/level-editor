#pragma once
#include "Toolbar.h"

class Blue : public Toolbar
{
public:
	Blue() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		m_sprite[BLUE].setPosition(BLUE * P_SIZE, 0);
		window.draw(m_sprite[BLUE]);
	}

};
