#pragma once

#include <SFML\Graphics.hpp>

enum Toolbar_t {PACMAN,DEMON,COOKIE,WALL,SAVE,ERASE,CLEAR,RED,BLUE,GREEN};

const int NUM_OF_ICONS = 10;

class Toolbar
{
public:
	Toolbar() ;
	Toolbar(sf::RenderWindow & window);
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize) {}
	~Toolbar();

private:

	sf::Vector2f m_position;
	sf::Color m_color;
	sf::Texture m_pTexture[NUM_OF_ICONS];
	sf::Sprite m_photos[NUM_OF_ICONS];
	
};

 