#pragma once
#include "Toolbar.h"


class Demon : public Icon
{
public:
	Demon(Toolbar_t color) { m_color = color ; m_shape = DEMON;}

	void draw(sf::RenderWindow& window, sf::Vector2f pos, sf::Sprite sprite)
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
	};
private:
};