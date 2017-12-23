
#include "Board.h"

// board c-tor 
Board::Board(bool read) :
	m_read(read)
{
	m_new_icon._shape = NONE;
	m_new_icon._color = NONE;
	m_moving_rect.setSize(sf::Vector2f((float)P_SIZE, (float)P_SIZE));
	m_moving_rect.setFillColor(sf::Color::Transparent);
	read_data();
	m_toolbar.set_toolbar();
}

// draws the grid
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

// draw all the relevent objects 
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

// in case the user clicked on the mouse
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
			m_read = true;
			break;
		case ERASE:
			setToolbarRect(m_shape_rect, pos, sf::Color(0, 150, 255, 200));
			erase_mode = true;
			break;
		case CLEAR:
			m_read = false;
			clear_grid();
			window.close();
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
				if (m_pacman_placed)
					m_grid[(int)m_pacman_pos.x][(int)m_pacman_pos.y] = nullptr;
				m_grid[x][y] = std::make_unique < Pacman >(m_new_icon._color);
				m_pacman_pos = sf::Vector2f((float)x,(float)y);
				m_pacman_placed = true;
				break;
			case DEMON:
				m_grid[x][y] = std::make_unique < Demon > (m_new_icon._color);
				break;
			case COOKIE:
				m_grid[x][y] = std::make_unique < Cookie > (m_new_icon._color);
				break;
			case WALL:
				m_grid[x][y] = std::make_unique < Wall > (m_new_icon._color);
				break;
			}
		}
	}
}

// sets the rectangle around the toolbar icons 
void Board::setToolbarRect(sf::RectangleShape &rect,sf::Vector2f pos, sf::Color color)
{
	rect.setSize(sf::Vector2f((float)P_SIZE, (float)P_SIZE));
	rect.setFillColor(sf::Color::Transparent);
	rect.setOutlineThickness(2);
	rect.setPosition(pos);
	rect.setOutlineColor(color);
}

// draws the icons that the user picked
void Board::draw_icons(sf::RenderWindow & window)
{
	for (size_t i = 0; i < m_boardsize.x ; i++)
		for (size_t j = 0; j < m_boardsize.y; j++)
			if (m_grid[i][j] != nullptr)
				m_grid[i][j]->draw(window,sf::Vector2f(((float)j)*P_SIZE,((float)(i+1))*P_SIZE), m_toolbar.get_icon_sprite(m_grid[i][j]->getShape()));
}

// in case the mouse moved
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

// checks if the cursor is in the window
bool Board::in_window(sf::Event event)
{
	int x = event.mouseMove.x;
	int y = event.mouseMove.y;
	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));

	if (x > P_SIZE * m_boardsize.x || 
		y > P_SIZE * (m_boardsize.y + 1) ||
		x < 0 || y < 0)
		return false;

	return true;
}


// saves the board to a .txt file
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

// deletes all the objects from the board
void Board::clear_grid()
{
	for (size_t i = 0; i < m_boardsize.x; i++)
		for (size_t j = 0; j < m_boardsize.y; j++)
			m_grid[i][j] = nullptr;
}

// opens the file to read
bool Board::open_file(fstream& input)
{
	input.open("board.txt");
	if (!input.is_open())
		return false;
	return true;
}

// read data for the board - from the user or the .txt file
void Board::read_data()
{
	std::fstream input;
	
	if(open_file(input) && m_read)
	{
		char c;
		input >> m_boardsize.x >> m_boardsize.y;
		input.get();
		set_board();
	
		for (size_t i = 0; i < m_boardsize.x; i++)
			for (size_t j = 0; j < m_boardsize.y + 1; j++)
			{
				c = input.get();
				read_char(c, i, j);
			}
	}
	else
		read_from_usr();
}

// read data from the user
void Board::read_from_usr()
{
	std::cout << "please enter number of rows ";
	std::cin >> m_boardsize.x;
	std::cout << "please enter number of columns ";
	std::cin >> m_boardsize.y;
	if (m_boardsize.y < 10)
	{
		std::cerr << "too few columns, please enter more columns\n";
		read_from_usr();
	}
	set_board();
}

// write the red objects to the .txt file
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

// write the green objects to the .txt file
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

// write the blue objects to the .txt file
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

// read a char from the .txt file and save it to the board
void Board::read_char(const char c,const size_t i, const size_t j )
{
	
	switch (c)
	{
	case '#' :
		m_grid[i][j] = std::make_unique < Wall > (RED);
		break;
	case 'E' :
		m_grid[i][j] = std::make_unique < Wall > (GREEN);
		break;
	case 'D' :
		m_grid[i][j] = std::make_unique < Wall > (BLUE);
		break;
	case '*' :
		m_grid[i][j] = std::make_unique < Cookie > (RED);
		break;
	case 'I':
		m_grid[i][j] = std::make_unique < Cookie > (GREEN);
		break;
	case 'K' :
		m_grid[i][j] = std::make_unique < Cookie > (BLUE);
		break;
	case '%' :
		m_grid[i][j] = std::make_unique < Demon > (RED);
		break;
	case 'T' :
		m_grid[i][j] = std::make_unique < Demon > (GREEN);
		break;
	case 'G' :
		m_grid[i][j] = std::make_unique < Demon > (BLUE);
		break;
	case '@' :
		m_grid[i][j] = std::make_unique < Pacman > (RED);
		break;
	case 'W' :
		m_grid[i][j] = std::make_unique < Pacman > (GREEN);
		break;
	case 'S' :
		m_grid[i][j] = std::make_unique < Pacman > (BLUE);
		break;
	default:
		break;
	}
}

void Board::set_board()
{
	m_grid.resize((int)m_boardsize.x);
	for (size_t i = 0; i < m_boardsize.x; i++)
		m_grid[i].resize((int)m_boardsize.y);
}
