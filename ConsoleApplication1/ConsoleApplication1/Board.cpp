
#include "Board.h"




Board::Board(const sf::Vector2f boardsize, sf::RenderWindow&  window)
{
	read_board(boardsize);

	draw_new_page(window, boardsize);




}

void Board::draw_grid(sf::RenderWindow & window, const sf::Vector2f boardsize)
{
	float toolbar_gap = P_SIZE;
	sf::RectangleShape col(sf::Vector2f(1, (P_SIZE * boardsize.x)));
	sf::RectangleShape row(sf::Vector2f(P_SIZE * boardsize.y, 1));
	for (size_t i = 0; i < boardsize.y + 1; i++) // columns
	{
		col.setFillColor(sf::Color::White);
		col.setPosition((float)(i * P_SIZE), (float)P_SIZE);
		window.draw(col);
	}

	for (size_t i = 0; i < boardsize.x + 1; i++) //rows
	{
		row.setFillColor(sf::Color::White);
		row.setPosition(0, toolbar_gap);
		window.draw(row);
		toolbar_gap += P_SIZE;
	}
}

void Board::draw_new_page(sf::RenderWindow & window, const sf::Vector2f boardsize)
{
	//draw_backround(window);
	draw_grid(window, boardsize);
	m_toolbar.draw_toolbar(window);

}

void Board::draw_backround(sf::RenderWindow & window)
{
	sf::Texture pTexture;
	sf::Sprite background;
	pTexture.loadFromFile("photo.jpg");
	background.setTexture(pTexture);
	window.draw(background);
}


void Board::draw_back_rect(sf::RenderWindow & window, sf::Vector2i position, sf::Vector2f boardsize, sf::RectangleShape rect)
{
	int y = (position.y - (position.y % (int)(540 / boardsize.y)));
	int x = (position.x - (position.x % (int)(800 / (boardsize.x - 1))));
	sf::Vector2f pos((float)x, (float)y);
	rect.setPosition(pos);
	rect.setFillColor(sf::Color(255, 255, 255, 100));
	window.draw(rect);

}

void Board::mouse_button_released(sf::Event event)
{
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;
	Toolbar_t icon = m_toolbar.get_icon();

	switch (icon)
	{
	case PACMAN :
	}
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
	}
}
