#pragma once
#include "Toolbar.h"


class Clear : public Toolbar
{
public:
	Clear() : position(6 * 80, 0) {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		m_sprite[CLEAR].setPosition(CLEAR * P_SIZE, 0);
		window.draw(m_sprite[CLEAR]);
	}

private:
	sf::Vector2f position;

};