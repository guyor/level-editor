
#include "Board.h"




Board::Board(const sf::Vector2f size, sf::RenderWindow&  window) :
	m_boardsize(size), m_grid((int)size.x, vector < Icon * >((int)size.y))
{
	m_toolbar.set_toolbar();
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
	window.draw(m_shape_rect);
	window.draw(m_color_rect);

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

void Board::mouse_button_released(sf::Event event,sf::RenderWindow &window)
{
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;
	
	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));
	std::cout << pos.x << " " << pos.y << "\n";
	if (pos.y == 0) // means toolbar button was pressed
	{
		Toolbar_t icon = m_toolbar.get_icon_name(pos);
		
		switch (icon)
		{
		case PACMAN:
			m_new_icon._shape = PACMAN;
			setToolbarRect(m_shape_rect, pos, sf::Color(255, 150, 0, 200));
			break;
		case DEMON:
			m_new_icon._shape = DEMON;
			setToolbarRect(m_shape_rect, pos, sf::Color(255, 150, 0, 200));
			break;
		case COOKIE:
			m_new_icon._shape = COOKIE;
			setToolbarRect(m_shape_rect, pos, sf::Color(255, 150, 0, 200));
			break;
		case WALL:
			m_new_icon._shape = WALL;
			setToolbarRect(m_shape_rect, pos, sf::Color(255, 150, 0, 200));
			break;
		case SAVE:
			setToolbarRect(m_shape_rect, pos, sf::Color(255, 150, 0, 200));
			// write grid into .txt file
			break;
		case ERASE:
			setToolbarRect(m_shape_rect, pos, sf::Color(255, 150, 0, 200));
			// put a null and delte
			break;
		case CLEAR:
			setToolbarRect(m_shape_rect,pos, sf::Color(255,150,0,200));
			// erase all icons and save
			break;
		case RED:
			m_new_icon._color = RED;
			setToolbarRect(m_color_rect,pos, sf::Color::Red);
			break;
		case GREEN:
			m_new_icon._color = GREEN;
			setToolbarRect(m_color_rect, pos, sf::Color::Green);
			break;
		case BLUE:
			m_new_icon._color = BLUE;
			setToolbarRect(m_color_rect, pos, sf::Color::Blue);
			break;
		}
	}
	
	else // means a cell in the grid was pressed
	{
		int x = (int)pos.x / P_SIZE;
		int y = (int)pos.y / P_SIZE;
		switch (m_new_icon._shape)
		{
		case PACMAN:
			m_grid[x][y] = new Pacman(m_new_icon._color);
			break;
		case DEMON:
			m_grid[x][y] = new Demon(m_new_icon._color);
			break;
		case COOKIE:
			m_grid[x][y] = new Cookie(m_new_icon._color);
			break;
		case WALL:
			m_grid[x][y] = new Wall(m_new_icon._color);
			break;
		}
	}
	
}

void Board::setToolbarRect(sf::RectangleShape &rect,sf::Vector2f pos, sf::Color color)
{
	rect.setSize(sf::Vector2f((float)P_SIZE, (float)P_SIZE));
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineThickness(2);
	rect.setPosition(pos);
	rect.setOutlineColor(color);
}


void Board::draw_icons()
{
	for (size_t i = 0; i < m_boardsize.x ; i++)
		for (size_t j = 0; j < m_boardsize.y; j++)
		{
			if (m_grid[i][j] != NULL)
			{
				
			}
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
