#pragma once

#include <SFML\Graphics.hpp>


class Board
{
public:
	Board() {};
	~Board() {};

	Board(sf::Vector2f boardsize, sf::RenderWindow & window);
	void draw_rects(sf::RenderWindow & window, sf::Vector2f boardsize);

};

