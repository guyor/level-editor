
#include "Board.h"



Board::Board(sf::Vector2f boardsize, sf::RenderWindow&  window)
{
	draw(window, boardsize);
	
}

void Board::draw_rects(sf::RenderWindow & window, sf::Vector2f boardsize)
{
	for (size_t i = 0; i < boardsize.y + 1 ; i++) // columns
	{
		sf::RectangleShape rect(sf::Vector2f(1, 600));
		rect.setFillColor(sf::Color::Red);
		rect.setPosition(i * (800/boardsize.y), 0);
		window.draw(rect);
		
	}
	for (size_t i = 0; i < boardsize.x + 1 ; i++) //rows
	{
		sf::RectangleShape rect(sf::Vector2f(800, 1));
		rect.setFillColor(sf::Color::Red);
		rect.setPosition(0 , i * (600/boardsize.x));
		window.draw(rect);
	}
}

void Board::draw(sf::RenderWindow & window, sf::Vector2f boardsize)
{
	draw_backround(window);
	draw_rects(window, boardsize);
}

void Board::draw_backround(sf::RenderWindow & window)
{
	sf::Texture pTexture;
	sf::Sprite background;
	pTexture.loadFromFile("photo.jpg");
	background.setTexture(pTexture);
	window.draw(background);
}

