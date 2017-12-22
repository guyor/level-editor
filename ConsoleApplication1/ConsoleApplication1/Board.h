#pragma once

#include "Toolbar.h"
#include "Pacman.h"
#include "Demon.h"
#include "Cookie.h"
#include "Wall.h"
#include <fstream>
#include "Icon.h"
#include <memory>
using std::fstream;
using std::cerr;

struct Item
{
	Toolbar_t _shape;
	Toolbar_t _color;
};


class Board
{
public:
	Board() {};
	Board(bool read);
	~Board() {};

	void draw_grid(sf::RenderWindow & window);
	void draw(sf::RenderWindow & window);
	void mouse_button_released(sf::Event event, sf::RenderWindow & window);
	void draw_icons(sf::RenderWindow & window);
	void mouse_moved(sf::Event event,sf::RenderWindow & window);

	bool getRead() { return m_read; }
	bool in_window(sf::Event event);

	sf::Vector2f getBoardSize() { return m_boardsize; }
	sf::Vector2i get_mouse() { return m_mouse; };

private:
	void setToolbarRect(sf::RectangleShape &rect, sf::Vector2f pos, sf::Color color);
	void save_grid();
	void clear_grid();
	void read_data();
	void read_from_usr();
	void write_reds(std::ofstream &output,Toolbar_t shape);
	void write_greens(std::ofstream &output, Toolbar_t shape);
	void write_blues(std::ofstream &output, Toolbar_t shape);
	void read_char(const char c,size_t i,size_t j);
	void set_board();

	bool open_file(fstream& input);
	bool m_pacman_placed = false;
	bool m_read;
	bool erase_mode = true;

	Toolbar m_toolbar;
	vector < vector < std::unique_ptr < Icon > > > m_grid;
	Item m_new_icon;

	sf::Vector2i m_mouse;
	sf::Vector2f m_boardsize;
	sf::Vector2f m_pacman_pos;
	sf::RectangleShape m_shape_rect;
	sf::RectangleShape m_color_rect;
	sf::RectangleShape m_grid_rect;
	sf::RectangleShape m_moving_rect;
	sf::Sprite m_moving_icon;
};

