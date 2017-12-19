#pragma once

#include <SFML\Graphics.hpp>
#include <vector>

using std::vector;

enum Toolbar_t {PACMAN,DEMON,COOKIE,WALL,SAVE,ERASE,CLEAR,RED,BLUE,GREEN};

const int NUM_OF_ICONS = 10;
const unsigned int P_SIZE = 55;
const int SCALE = 64;

class Toolbar
{
public:
	Toolbar() ;
	~Toolbar();
	
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize) {}

	void draw_toolbar(sf::RenderWindow & window);
	Toolbar_t get_icon(sf::Vector2f vec);

protected:

	sf::Vector2f m_positions[NUM_OF_ICONS];
	sf::Color m_color;
	sf::Texture m_pTexture[NUM_OF_ICONS];
	sf::Sprite m_sprite[NUM_OF_ICONS];
	
};

 