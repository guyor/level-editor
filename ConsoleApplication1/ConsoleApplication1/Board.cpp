
#include "Board.h"




Board::Board()
{
	read_data();
	m_toolbar.set_toolbar();
}

void Board::draw_grid(sf::RenderWindow & window)
{
	float toolbar_gap = P_SIZE;
	sf::RectangleShape col(sf::Vector2f(1, (P_SIZE * m_boardsize.x)));
	sf::RectangleShape row(sf::Vector2f(P_SIZE * m_boardsize.y, 1));
	for (size_t i = 0; i < m_boardsize.y ; i++) // columns
	{
		col.setFillColor(sf::Color::White);
		col.setPosition((float)(i * P_SIZE), (float)P_SIZE);
		window.draw(col);
	}

	for (size_t i = 0; i < m_boardsize.x ; i++) //rows
	{
		row.setFillColor(sf::Color::White);
		row.setPosition(0, toolbar_gap);
		window.draw(row);
		toolbar_gap += P_SIZE;
	}
	
}

void Board::draw(sf::RenderWindow & window)
{
	//draw_backround(window);
	draw_grid(window);
	m_toolbar.draw_toolbar(window);
	window.draw(m_shape_rect);
	window.draw(m_color_rect);
	draw_icons(window);
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
		std::cout << x << " " << y << "\n";
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


void Board::draw_icons(sf::RenderWindow & window)
{
	for (size_t i = 0; i < m_boardsize.x ; i++)
		for (size_t j = 0; j < m_boardsize.y; j++)
			if (m_grid[i][j] != nullptr)
				m_grid[i][j]->draw(window,sf::Vector2f(i*P_SIZE,j*P_SIZE), m_toolbar.get_icon_sprite(m_grid[i][j]->getShape()));
}

bool Board::open_file(ifstream& input)
{
	input.open("board.txt");
	if (!input.is_open())
		return false;
	return true;
}

void Board::read_data()
{
	ifstream input;
	if (open_file(input))
	{
		char c;
		input >> m_boardsize.x >> m_boardsize.y ;
		m_grid.assign((int)m_boardsize.x,vector < Icon * >((int)m_boardsize.y, nullptr));

		for (size_t i = 0; i < m_boardsize.x; i++)
			for (size_t j = 0; j < m_boardsize.y; j++)
			{
				input >> c;
				read_char(c, i, j);
			}
	}
	else
	{
		std::cout << "please enter number of rows ";
		std::cin >> m_boardsize.x;
		std::cout << "please enter number of columns ";
		std::cin >> m_boardsize.y;
		m_grid.assign((int)m_boardsize.x, vector < Icon * >((int)m_boardsize.y, nullptr));
	}
}

void Board::read_char(const char c,const size_t i, const size_t j )
{
	switch (c)
	{
	case '#' :
		m_grid[i][j] = new Wall(RED);
		break;
	case 'E' :
		m_grid[i][j] = new Wall(GREEN);
		break;
	case 'D' :
		m_grid[i][j] = new Wall(BLUE);
		break;
	case '*' :
		m_grid[i][j] = new Cookie(RED);
		break;
	case 'I':
		m_grid[i][j] = new Cookie(GREEN);
		break;
	case 'K' :
		m_grid[i][j] = new Cookie(BLUE);
		break;
	case '%' :
		m_grid[i][j] = new Demon(RED);
		break;
	case 'T' :
		m_grid[i][j] = new Demon(GREEN);
		break;
	case 'G' :
		m_grid[i][j] = new Demon(BLUE);
		break;
	case '@' :
		m_grid[i][j] = new Pacman(RED);
		break;
	case 'W' :
		m_grid[i][j] = new Pacman(GREEN);
		break;
	case 'S' :
		m_grid[i][j] = new Pacman(BLUE);
		break;
	default:
		break;
	}
}
