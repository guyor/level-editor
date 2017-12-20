#pragma once
#include "Toolbar.h"

class Cookie : public Icon
{
public:
	Cookie(Toolbar_t color) { m_color = color; m_shape = COOKIE;};

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