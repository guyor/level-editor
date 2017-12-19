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
#include "Blue.h"
#include "Red.h"
#include "Green.h"

using std::ifstream;
using std::vector;
using std::string;
using std::cerr;

const unsigned int P_SIZE = 64;

class Board
{
public:
	Board() {};
	~Board() {};

	Board(const sf::Vector2f boardsize, sf::RenderWindow & window);
	void draw_rects(sf::RenderWindow & window,const sf::Vector2f boardsize);
	void draw_new_page(sf::RenderWindow & window,const sf::Vector2f boardsize);
	void draw_backround(sf::RenderWindow & window);
	void draw_icons(sf::RenderWindow & window,const sf::Vector2f boardsize);
	void set_mouse(const sf::Vector2i & new_mouse) { m_mouse = new_mouse; };
	void draw_back_rect(sf::RenderWindow & window, sf::Vector2i position, sf::Vector2f boardsize, sf::RectangleShape rect);
	sf::Vector2i get_mouse() { return m_mouse; };
	void mouse_button_released(sf::Event event);

private:
	vector<string> m_Matrix;
	void Board::Open_File(ifstream & input);
	void read_board(const sf::Vector2f boardsize);
	sf::Vector2i m_mouse;
	Icons * m_icons[10];
};

