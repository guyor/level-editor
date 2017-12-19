#pragma once
#include "Toolbar.h"


class Demon : public Toolbar
{
public:
	Demon() : position(80, 0)
	{
		
	};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize)
	{
		m_sprite[DEMON].setPosition(DEMON * P_SIZE, 0);
		window.draw(m_sprite[DEMON]);
	}

private:
	sf::Vector2f position;
};