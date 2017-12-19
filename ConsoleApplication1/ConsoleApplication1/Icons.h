#pragma once

#include <SFML\Graphics.hpp>

const int NUM_OF_ICONS = 10;

class Icons
{
public:
	Icons() {
		for (size_t i = 0; i < NUM_OF_ICONS; i++)
		{
			m_rects[i].setSize((sf::Vector2f(80, 60)));

		}
	};
	Icons(sf::RenderWindow & window);
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize) {}
	~Icons();

private:

	sf::Vector2f m_position;
	sf::Color m_color;
	sf::Texture m_pTexture[NUM_OF_ICONS];
	sf::Sprite m_photos[NUM_OF_ICONS];
	
};

 