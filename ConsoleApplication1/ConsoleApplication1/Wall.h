#pragma once
#include "Icons.h"

class Wall : public Icons
{
public:
	Wall() {};
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize){}

};