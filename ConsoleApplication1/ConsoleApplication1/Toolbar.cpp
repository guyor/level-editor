
#include "Toolbar.h"

// toolbar c-tor
Toolbar::Toolbar()
{
	for (size_t i = 0; i < NUM_OF_ICONS; i++)
		m_positions[i] = sf::Vector2f(i *(float)P_SIZE, 0);
}

// toolber d-tor
Toolbar::~Toolbar()
{
}

// load textures  and set the sprites to the toolbar
void Toolbar::set_toolbar()
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
		float x = m_sprite[0].getGlobalBounds().height;
		float y = m_sprite[0].getScale().y;
		m_sprite[i].setScale(sf::Vector2f(((float)P_SIZE / m_sprite[i].getGlobalBounds().height),((float)P_SIZE / m_sprite[i].getGlobalBounds().height)));
		m_sprite[i].setPosition(m_positions[i]);
	}
	
}


// draws the toolbar
void Toolbar::draw_toolbar(sf::RenderWindow & window)
{
	for (size_t i = 0; i < NUM_OF_ICONS; i++)
		window.draw(m_sprite[i]);
}

// returns the icons name
Toolbar_t Toolbar::get_icon_name(sf::Vector2f vec)
{
	for (size_t i = 0; i < NUM_OF_ICONS ; i++)
	{
		if (m_positions[i] == vec)
			return (Toolbar_t)i;
	}
	return (Toolbar_t)0;
}



