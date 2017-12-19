#pragma once

#include <SFML\Graphics.hpp>

enum Toolbar_t {PACMAN,DEMON,COOKIE,WALL,SAVE,ERASE,CLEAR,RED,BLUE,GREEN};

const int NUM_OF_ICONS = 10;
const unsigned int P_SIZE = 64;

class Toolbar
{
public:
	Toolbar() ;
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize) {}
	~Toolbar();

protected:

	void load_sprites();
	sf::Vector2f m_position;
	sf::Color m_color;
	sf::Texture m_pTexture[NUM_OF_ICONS];
	sf::Sprite m_sprite[NUM_OF_ICONS];
	
};

 