#pragma once

#include <SFML\Graphics.hpp>

class Icons
{
public:
	Icons() {};
	Icons(sf::RenderWindow & window);
	~Icons();

private:

	sf::Vector2f m_position;
	sf::Color m_color;


};

