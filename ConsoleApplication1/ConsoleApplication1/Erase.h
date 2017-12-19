#pragma once
#include "Toolbar.h"

class Erase : public Toolbar
{
public:
	Erase() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		m_sprite[ERASE].setPosition(ERASE * P_SIZE, 0);
		window.draw(m_sprite[ERASE]);
	}

};