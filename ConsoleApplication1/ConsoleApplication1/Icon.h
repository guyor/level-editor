#pragma once
#include <SFML\Graphics.hpp>


class Icon
{
public:
	

protected:
	virtual void draw(sf::RenderWindow window, sf::Vector2f pos, sf::Sprite sprites[]) {};
	Toolbar_t m_color;
};