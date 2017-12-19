
#include "Board.h"




Board::Board(const sf::Vector2f size, sf::RenderWindow&  window) :
	m_boardsize(size)
{
	// resize vector size
	read_board();

	draw_new_page(window);




}

void Board::draw_grid(sf::RenderWindow & window)
{
	float toolbar_gap = P_SIZE;
	sf::RectangleShape col(sf::Vector2f(1, (P_SIZE * m_boardsize.x)));
	sf::RectangleShape row(sf::Vector2f(P_SIZE * m_boardsize.y, 1));
	for (size_t i = 0; i < m_boardsize.y + 1; i++) // columns
	{
		col.setFillColor(sf::Color::White);
		col.setPosition((float)(i * P_SIZE), (float)P_SIZE);
		window.draw(col);
	}

	for (size_t i = 0; i < m_boardsize.x + 1; i++) //rows
	{
		row.setFillColor(sf::Color::White);
		row.setPosition(0, toolbar_gap);
		window.draw(row);
		toolbar_gap += P_SIZE;
	}
}

void Board::draw_new_page(sf::RenderWindow & window)
{
	//draw_backround(window);
	draw_grid(window);
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
	
	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));

	if (pos.x == 0) // means toolbar button was pressed
	{
		Toolbar_t icon = m_toolbar.get_icon(pos);
		switch (icon)
		{
		case PACMAN:
			
			break;
		case DEMON:
			break;
		case COOKIE:
			break;
		case WALL:
			break;
		case SAVE:
			break;
		case ERASE:
			break;
		case CLEAR:
			break;
		case RED:
			break;
		case GREEN:
			break;
		case BLUE:
			break;
		}
	}
	else // means a cell in the grid was pressed
	{
		//add icon that i have to the data structure
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

void Board::read_board()
{
	ifstream input;
	Open_File(input);

	std::string line;
	getline(input, line);

	for (int i = 0; i < m_boardsize.x; i++)
	{
		getline(input, line);
	}
}
