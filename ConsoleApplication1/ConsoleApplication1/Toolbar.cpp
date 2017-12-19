
#include "Toolbar.h"


Toolbar::Toolbar()
{
	for (size_t i = 0; i < NUM_OF_ICONS; i++)
		m_positions[i] = sf::Vector2f(i *P_SIZE, 0);
}


Toolbar::~Toolbar()
{
}

void Toolbar::draw_toolbar(sf::RenderWindow & window)
{
	m_pTexture[PACMAN].loadFromFile("pacman.png");
	m_pTexture[DEMON].loadFromFile("demon.png");
	m_pTexture[COOKIE].loadFromFile("cookie.png");
	m_pTexture[WALL].loadFromFile("wall.png");
	m_pTexture[SAVE].loadFromFile("save.png");
	m_pTexture[CLEAR].loadFromFile("clear.png");
	m_pTexture[ERASE].loadFromFile("erase.png");
	m_pTexture[RED].loadFromFile("red.png");
	m_pTexture[BLUE].loadFromFile("blue.png");
	m_pTexture[GREEN].loadFromFile("green.png");

	for (size_t i = 0; i < NUM_OF_ICONS; i++)
	{
		m_sprite[i].setTexture(m_pTexture[i]);
		m_sprite[i].setScale(sf::Vector2f(((float)P_SIZE / SCALE),((float)P_SIZE / SCALE)));
		m_sprite[i].setPosition(m_positions[i]);
		window.draw(m_sprite[i]);
	}
	
}

Toolbar_t Toolbar::get_icon(sf::Vector2f vec)
{
	for (size_t i = 0; i < NUM_OF_ICONS ; i++)
		if (m_positions[i] == vec)
			return (Toolbar_t)i;
}

