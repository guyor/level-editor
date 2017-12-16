#pragma once

#include <SFML\Graphics.hpp>
#include "Icons.h"
#include <vector>
#include "Pacman.h"

class Board
{
public:
	Board() {};
	~Board() {};

	Board(sf::Vector2f boardsize, sf::RenderWindow & window);
	void draw_rects(sf::RenderWindow & window, sf::Vector2f boardsize);
	void draw(sf::RenderWindow & window, sf::Vector2f boardsize);
	void draw_backround(sf::RenderWindow & window);
};

