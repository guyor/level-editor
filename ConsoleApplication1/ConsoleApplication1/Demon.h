#pragma once
#include "Toolbar.h"


class Demon : public Icon
{
public:
	Demon(Toolbar_t color) { m_color = color ; }

	void draw(sf::RenderWindow window, sf::Vector2f pos, sf::Sprite sprites[])
	{
		sprites[DEMON].setPosition(pos);
		window.draw(sprites[DEMON]);
	};
private:
};