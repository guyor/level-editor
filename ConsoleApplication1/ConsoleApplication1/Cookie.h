#pragma once
#include "Toolbar.h"

class Cookie : public Icon
{
public:
	Cookie(Toolbar_t color) : m_color(color) {};

	void draw(sf::RenderWindow window, sf::Vector2f pos, sf::Sprite sprites[])
	{
		sprites[COOKIE].setPosition(pos);
		window.draw(sprites[COOKIE]);
	};


private:
	Toolbar_t m_color;
};