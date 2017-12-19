#pragma once
#include "Toolbar.h"

class Save : public Toolbar
{
public:
	Save() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		m_sprite[SAVE].setPosition(SAVE * P_SIZE, 0);
		window.draw(m_sprite[SAVE]);
	}

};