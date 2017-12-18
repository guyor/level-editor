
#include "Board.h"




Board::Board(const sf::Vector2f boardsize, sf::RenderWindow&  window)
{
	read_board(boardsize);

	draw(window, boardsize);
	

	

}

void Board::draw_rects(sf::RenderWindow & window,const sf::Vector2f boardsize)
{
	float y = 60;
	sf::RectangleShape col(sf::Vector2f(1, 540));
	sf::RectangleShape row(sf::Vector2f(800, 1));
	for (size_t i = 0; i < boardsize.y + 1; i++) // columns
	{
		col.setFillColor(sf::Color::White);
		col.setPosition(i * (800/boardsize.y), 60);
		window.draw(col);
		
	}

	for (size_t i = 1; i < boardsize.x  + 2; i++) //rows
	{
		row.setFillColor(sf::Color::White);
		row.setPosition(0 , y);
		y += ((540) / (boardsize.x));
		window.draw(row);
	}
}

void Board::draw(sf::RenderWindow & window,const sf::Vector2f boardsize)
{
	//draw_backround(window);
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

void Board::draw_back_rect(sf::RenderWindow & window, sf::Vector2i position, sf::Vector2f boardsize, sf::RectangleShape rect)
{
	int y = (position.y - (position.y % (int)(540 / boardsize.y)));
	int x = (position.x - (position.x % (int)(800 / (boardsize.x - 1))));
	sf::Vector2f pos((float)x, (float)y);
	rect.setPosition(pos);
	rect.setFillColor(sf::Color(255,255,255,100));
	window.draw(rect);

}

void Board::mouse_button_released(sf::Event event)
{
	
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
