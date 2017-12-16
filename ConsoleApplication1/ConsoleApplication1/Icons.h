#pragma once

#include <SFML\Graphics.hpp>

class Icons
{
public:
	Icons() {};
	Icons(sf::RenderWindow & window);
	virtual void draw(sf::RenderWindow & window, sf::Vector2f boardsize) {}
	~Icons();

private:

	sf::Vector2f m_position;
	sf::Color m_color;


};

