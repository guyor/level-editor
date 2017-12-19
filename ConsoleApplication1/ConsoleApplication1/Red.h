#pragma once
#include "Toolbar.h"

class Red : public Toolbar
{
public:
	Red() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		m_sprite[RED].setPosition(RED * P_SIZE, 0);
		window.draw(m_sprite[RED]);
	}

};