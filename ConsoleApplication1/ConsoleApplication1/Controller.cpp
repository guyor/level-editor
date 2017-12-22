
#include "Controller.h"


void Controller::run()
{
	
	do
	{
		m_read = true;
		Board board;
		int x = (int)board.getBoardSize().x;
		int y = (int)board.getBoardSize().y;
		sf::RenderWindow window(sf::VideoMode(y * P_SIZE,(x + 1) * P_SIZE), "SFML works!");

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
					board.mouse_moved(event, window);

					break;

				}
				if (event.type == sf::Event::Closed)
					window.close();
			}
			window.display();
		}
		m_read = board.getRead();
	} while (!m_read);
	
}



