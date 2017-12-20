#pragma once

#include "Toolbar.h"
#include "Icon.h"

#include <iostream>

class Pacman : public Icon
{
public:
	Pacman(Toolbar_t color) : m_color(color) {};
	
	void draw(sf::RenderWindow window,sf::Vector2f pos, sf::Sprite sprites[])
	{
		sprites[PACMAN].setPosition(pos);
		window.draw(sprites[PACMAN]);
	}
	

private:
	Toolbar_t m_color;
};