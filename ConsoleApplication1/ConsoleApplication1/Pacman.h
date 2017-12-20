#pragma once

#include "Toolbar.h"
#include "Icon.h"

#include <iostream>

class Pacman : public Icon
{
public:
	Pacman(Toolbar_t color) { m_color = color; m_shape = PACMAN; }
	
	void draw(sf::RenderWindow &window,sf::Vector2f pos, sf::Sprite sprite)
	{
		switch (m_color)
		{
		case RED:
			sprite.setColor(sf::Color::Red);
			break;
		case GREEN:
			sprite.setColor(sf::Color::Green);
			break;
		case BLUE:
			sprite.setColor(sf::Color::Blue);
			break;
		default:
			break;
		}
		sprite.setPosition(pos);
		window.draw(sprite);
	}


private:

};