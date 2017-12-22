#pragma once

#include "Toolbar.h"
#include "Icon.h"

#include <iostream>

class Pacman : public Icon
{
public:
	// pacman c-tor
	Pacman(Toolbar_t color) { m_color = color; m_shape = PACMAN; }
	
	// draw pacman icon
	void draw(sf::RenderWindow &window,sf::Vector2f pos, sf::Sprite sprite)
	{
		switch (m_color)
		{
		case RED:
			sprite.setColor(sf::Color(255,0,0,230));
			break;
		case GREEN:
			sprite.setColor(sf::Color::Green);
			break;
		case BLUE:
			sprite.setColor(sf::Color(25,25,255,255));
			break;
		default:
			break;
		}
		sprite.setPosition(pos);
		window.draw(sprite);
	}


private:

};