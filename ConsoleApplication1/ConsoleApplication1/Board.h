#pragma once

#include <SFML\Graphics.hpp>
#include "Toolbar.h"
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
#include "Icon.h"

using std::ifstream;

using std::string;
using std::cerr;

struct Item
{
	Toolbar_t _shape;
	Toolbar_t _color;
};


class Board
{
public:
	Board();
	~Board() {};

	void draw_grid(sf::RenderWindow & window);
	void draw(sf::RenderWindow & window);
	void draw_backround(sf::RenderWindow & window);
	void set_mouse(const sf::Vector2i & new_mouse) { m_mouse = new_mouse; }
	void draw_back_rect(sf::RenderWindow & window, sf::Vector2i position, sf::Vector2f boardsize, sf::RectangleShape rect);
	sf::Vector2i get_mouse() { return m_mouse; };
	void mouse_button_released(sf::Event event, sf::RenderWindow & window);
	void setToolbarRect(sf::RectangleShape &rect, sf::Vector2f pos, sf::Color color);
	sf::Vector2f getBoardSize() { return m_boardsize; }
	void draw_icons();

private:
	bool open_file(ifstream& input);
	void read_data();
	void read_char(const char c,size_t i,size_t j);
	sf::Vector2i m_mouse;
	Toolbar m_toolbar;
	sf::Vector2f m_boardsize;
	vector < vector < Icon * > > m_grid;
	Item m_new_icon;
	sf::RectangleShape m_shape_rect;
	sf::RectangleShape m_color_rect;
	sf::RectangleShape m_grid_rect;
	
};

