#pragma once
#include "Toolbar.h"


class Icon
{
public:
	virtual void draw(sf::RenderWindow &window, sf::Vector2f pos, sf::Sprite sprite) {};
	Toolbar_t getShape() { return m_shape; }
	Toolbar_t getColor() { return m_color; }

protected:
	Toolbar_t m_color;
	Toolbar_t m_shape;
};