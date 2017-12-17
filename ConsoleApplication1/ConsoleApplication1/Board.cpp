
#include "Board.h"




Board::Board(const sf::Vector2f boardsize, sf::RenderWindow&  window)
{
	read_board(boardsize);

	draw(window, boardsize);
	

	

}

void Board::draw_rects(sf::RenderWindow & window,const sf::Vector2f boardsize)
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
		rect.setPosition(0 , i * 600/(boardsize.x));
		window.draw(rect);
	}
}

void Board::draw(sf::RenderWindow & window,const sf::Vector2f boardsize)
{
	draw_backround(window);
	draw_rects(window, boardsize);
	draw_icons(window,boardsize);
}

void Board::draw_backround(sf::RenderWindow & window)
{
	sf::Texture pTexture;
	sf::Sprite background;
	pTexture.loadFromFile("photo.jpg");
	background.setTexture(pTexture);
	window.draw(background);
}

void Board::draw_icons(sf::RenderWindow & window,const sf::Vector2f boardsize)
{
	Icons * icons[10];
	icons[0] = new Pacman;
	icons[1] = new Demon;
	icons[2] = new Cookie;
	icons[3] = new Wall;
	icons[4] = new Save;
	icons[5] = new Erase;
	icons[6] = new Clear;
	icons[7] = new Red;
	icons[8] = new Green;
	icons[9] = new Blue;

	for (size_t i = 0; i < 10; i++)
		icons[i]->draw(window, boardsize);
	
}

void Board::draw_back_rect(sf::RenderWindow & window, sf::Vector2f position, sf::Vector2f boardsize)
{
	sf::RectangleShape rect(sf::Vector2f(801 / boardsize.y, 601 / boardsize.x));
	rect.setPosition(position);
	rect.setFillColor(sf::Color::Transparent);
	window.draw(rect);

}

// open the .txt file to read from 
void Board::Open_File(ifstream & input)
{
	input.open("board.txt");
	if (!input.is_open())
	{
		cerr << "cannot open file";
		exit(EXIT_FAILURE);
	}
}

void Board::read_board(const sf::Vector2f boardsize)
{
	ifstream input;
	Open_File(input);

	std::string line;
	getline(input, line);

	for (int i = 0; i < boardsize.x; i++)
	{
		getline(input, line);
		m_Matrix.push_back(line);
	}
}
