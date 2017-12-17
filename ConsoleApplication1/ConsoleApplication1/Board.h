#pragma once

#include <SFML\Graphics.hpp>
#include "Icons.h"
#include <vector>
#include "Pacman.h"
#include "Demon.h"
#include "Cookie.h"
#include "Wall.h"
#include "Save.h"
#include "Erase.h"
#include "Clear.h"
#include <fstream>
#include <string>

using std::ifstream;
using std::vector;
using std::string;
using std::cerr;

class Board
{
public:
	Board() {};
	~Board() {};

	Board(sf::Vector2f boardsize, sf::RenderWindow & window);
	void draw_rects(sf::RenderWindow & window, sf::Vector2f boardsize);
	void draw(sf::RenderWindow & window, sf::Vector2f boardsize);
	void draw_backround(sf::RenderWindow & window);
	void draw_icons(sf::RenderWindow & window, sf::Vector2f boardsize);

private:
	vector<string> m_Matrix;
	void Board::Open_File(ifstream & input);
	void read_board(sf::Vector2f boardsize);
};

