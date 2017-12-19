
#include "Toolbar.h"


Toolbar::Toolbar()
{
	load_sprites();
	
}


Toolbar::~Toolbar()
{
}

void Toolbar::load_sprites()
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
		m_sprite[i].setTexture(m_pTexture[i]);
}

