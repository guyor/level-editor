
#include "Controller.h"

// runs the level editor
void Controller::run()
{
	
	do
	{
		Board board(m_read);
		m_read = true;
		int x = (int)board.getBoardSize().x;
		int y = (int)board.getBoardSize().y;
		sf::RenderWindow window(sf::VideoMode(y * P_SIZE,(x + 1) * P_SIZE), "SFML works!",sf::Style::Titlebar | sf::Style::Close);

		while (window.isOpen())
		{
			window.clear();
			board.draw(window);
			sf::Event event;
			while (window.pollEvent(event))
			{
				switch (event.type)
				{
				case sf::Event::Closed:
					window.close();
					break;
				case sf::Event::MouseButtonReleased:
					board.mouse_button_released(event, window);
					break;
				case sf::Event::MouseMoved:
					if (board.in_window(event))
						board.mouse_moved(event, window);
					break;

				}
				if (event.type == sf::Event::Closed)
				{
					m_out = true;
					window.close();
				}

			}
			window.display();
		}
		m_read = board.getRead();
	} while (!m_read && !m_out);
	
}



