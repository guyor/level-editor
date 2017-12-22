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
	//void set_mouse(const sf::Vector2i & new_mouse) { m_mouse = new_mouse; }
	sf::Vector2i get_mouse() { return m_mouse; };
	void mouse_button_released(sf::Event event, sf::RenderWindow & window);

	sf::Vector2f getBoardSize() { return m_boardsize; }
	void draw_icons(sf::RenderWindow & window);
	void mouse_moved(sf::Event event,sf::RenderWindow & window);
	bool getRead() { return m_read; }
	bool in_window(sf::Event event);

private:
	void setToolbarRect(sf::RectangleShape &rect, sf::Vector2f pos, sf::Color color);
	vector< vector<int> > vec;
	void save_grid();
	void clear_grid();
	bool open_file(fstream& input);
	void read_data();
	void read_from_usr();
	void write_reds(std::ofstream &output,Toolbar_t shape);
	void write_greens(std::ofstream &output, Toolbar_t shape);
	void write_blues(std::ofstream &output, Toolbar_t shape);
	void read_char(const char c,size_t i,size_t j);
	sf::Vector2i m_mouse;
	Toolbar m_toolbar;
	sf::Vector2f m_boardsize;
	vector < vector < std::unique_ptr < Icon > > > m_grid;
	Item m_new_icon;
	sf::RectangleShape m_shape_rect;
	sf::RectangleShape m_color_rect;
	sf::RectangleShape m_grid_rect;
	sf::RectangleShape m_moving_rect;
	sf::Sprite m_moving_icon;
	bool erase_mode = true;
	sf::Vector2f m_pacman_pos;
	bool m_pacman_placed = false;
	bool m_read;
	void set_board();


};

