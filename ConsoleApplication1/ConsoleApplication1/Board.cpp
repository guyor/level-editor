
#include "Board.h"




Board::Board()
{
	m_new_icon._shape = NONE;
	m_new_icon._color = NONE;
	m_moving_rect.setSize(sf::Vector2f((float)P_SIZE, (float)P_SIZE));
	m_moving_rect.setFillColor(sf::Color::Transparent);
	pacman_placed = false;
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
	erase_mode ? window.draw(m_moving_rect) : window.draw(m_moving_icon);
}

void Board::draw_backround(sf::RenderWindow & window)
{
	sf::Texture pTexture;
	sf::Sprite background;
	pTexture.loadFromFile("photo.jpg");
	background.setTexture(pTexture);
	window.draw(background);
}



void Board::mouse_button_released(sf::Event event,sf::RenderWindow &window)
{
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;
	
	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));
	if (pos.y == 0) // means toolbar button was pressed
	{
		erase_mode = false;
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
			setToolbarRect(m_shape_rect, pos, sf::Color(0, 150, 255, 200));
			save_grid();
			break;
		case ERASE:
			setToolbarRect(m_shape_rect, pos, sf::Color(0, 150, 255, 200));
			erase_mode = true;
			break;
		case CLEAR:
			//setToolbarRect(m_shape_rect, pos, sf::Color(0, 150, 255, 200));
			//erase_mode = true;
			m_clear = true;
			window.close();
			clear_grid();
			break;
		case RED:
			m_new_icon._color = RED;
			setToolbarRect(m_color_rect, pos, sf::Color::Red);
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
		int x = ((int)pos.y / P_SIZE) - 1;
		int y = (int)pos.x / P_SIZE;
		if (erase_mode)
			m_grid[x][y] = nullptr;
		else if(m_grid[x][y] == nullptr)
		{
			switch (m_new_icon._shape)
			{
			case PACMAN:
				if (pacman_placed)
					m_grid[m_pacman_pos.x][m_pacman_pos.y] = nullptr;
				m_grid[x][y] = new Pacman(m_new_icon._color);
				m_pacman_pos = sf::Vector2f(x,y);
				pacman_placed = true;
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
				m_grid[i][j]->draw(window,sf::Vector2f(((float)j)*P_SIZE,((float)(i+1))*P_SIZE), m_toolbar.get_icon_sprite(m_grid[i][j]->getShape()));
}

void Board::mouse_moved(sf::Event event,sf::RenderWindow & window)
{
	int x = event.mouseMove.x;
	int y = event.mouseMove.y;

	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));
	x = ((int)pos.y / P_SIZE) - 1;
	y = (int)pos.x / P_SIZE;

	if (pos.y != 0)
	{
		m_moving_rect.setFillColor(sf::Color(255, 0, 0, 150));
		if (m_grid[x][y] != nullptr && erase_mode)
			m_moving_rect.setFillColor(sf::Color(0, 255, 0, 50));
		m_moving_rect.setPosition(pos);
		switch (m_new_icon._shape)
		{
		case PACMAN:
			m_moving_icon = m_toolbar.get_icon_sprite(PACMAN);
			break;
		case DEMON:
			m_moving_icon = m_toolbar.get_icon_sprite(DEMON);
			break;
		case COOKIE:
			m_moving_icon = m_toolbar.get_icon_sprite(COOKIE);
			break;
		case WALL:
			m_moving_icon = m_toolbar.get_icon_sprite(WALL);
			break;
		}
		m_moving_icon.setPosition(pos);
		switch (m_new_icon._color)
		{
		case RED :
			m_moving_icon.setColor(sf::Color(255, 0, 0, 130));
			break;
		case GREEN:
			m_moving_icon.setColor(sf::Color(0, 255, 0, 130));
			break;
		case BLUE:
			m_moving_icon.setColor(sf::Color(0, 0, 255, 130));
			break;
		}
	}
}


void Board::save_grid()
{
	std::ofstream output;
	output.open("board.txt");
	if (!output.is_open())
	{
		std::cerr << "could not open board.txt";
		getchar();
		exit(EXIT_FAILURE);
	}

	output << m_boardsize.x << "\n" << m_boardsize.y << "\n";
	for (size_t i = 0; i < m_boardsize.x; i++)
	{
		for (size_t j = 0; j < m_boardsize.y; j++)
		{
			if (m_grid[i][j] == nullptr)
				output << " ";
			else
				switch (m_grid[i][j]->getColor())
				{
				case RED:
					write_reds(output, m_grid[i][j]->getShape());
					break;
				case GREEN:
					write_greens(output, m_grid[i][j]->getShape());
					break;
				case BLUE:
					write_blues(output, m_grid[i][j]->getShape());
					break;
				}
		}
		output << "\n";
	}
		
			

}

void Board::clear_grid()
{
	for (size_t i = 0; i < m_boardsize.x; i++)
		for (size_t j = 0; j < m_boardsize.y; j++)
			m_grid[i][j] = nullptr;
}

bool Board::open_file(fstream& input)
{
	input.open("board.txt");
	if (!input.is_open())
		return false;
	return true;
}

void Board::read_data()
{
	std::fstream input;
	if (open_file(input))
	{
		char c;
		input >> m_boardsize.x >> m_boardsize.y ;
		input.get();
		m_grid.assign((int)m_boardsize.x,vector < Icon * >((int)m_boardsize.y, nullptr));

		for (size_t i = 0; i < m_boardsize.x; i++)
			for (size_t j = 0; j < m_boardsize.y + 1; j++)
			{
				c = input.get();
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

void Board::write_reds(std::ofstream &output, Toolbar_t shape)
{
	switch (shape)
	{
	case PACMAN:
		output << "@";
		break;
	case DEMON:
		output << "%";
		break;
	case COOKIE:
		output << "*";
		break;
	case WALL:
		output << "#";
		break;
	}
}

void Board::write_greens(std::ofstream &output, Toolbar_t shape)
{
	switch (shape)
	{
	case PACMAN:
		output << "W";
		break;
	case DEMON:
		output << "T";
		break;
	case COOKIE:
		output << "I";
		break;
	case WALL:
		output << "E";
		break;
	}
}

void Board::write_blues(std::ofstream &output, Toolbar_t shape)
{
	switch (shape)
	{
	case PACMAN:
		output << "S";
		break;
	case DEMON:
		output << "G";
		break;
	case COOKIE:
		output << "K";
		break;
	case WALL:
		output << "D";
		break;
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
