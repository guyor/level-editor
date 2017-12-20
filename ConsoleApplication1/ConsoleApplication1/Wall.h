#pragma once
#include "Toolbar.h"

class Wall : public Icon
{
public:
	Wall(Toolbar_t color) { m_color = color; }

	void draw(sf::RenderWindow window, sf::Vector2f pos, sf::Sprite sprites[])
	{
		sprites[WALL].setPosition(pos);
		window.draw(sprites[WALL]);
	};


private:

};