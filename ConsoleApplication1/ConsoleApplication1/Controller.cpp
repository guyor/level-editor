
#include "Controller.h"


void Controller::run()
{
	sf::RenderWindow window(sf::VideoMode((int)m_y * P_SIZE , (int)(m_x + 1) * P_SIZE), "SFML works!");
	
	while (window.isOpen())
	{
		window.clear();

		sf::Event event;
		while (window.pollEvent(event))
		{
			switch(event.type)
			{
			case sf::Event::Closed:
					window.close();
					break;
			case sf::Event::MouseButtonReleased:
				m_board.mouse_button_released(event,window);
				break;
				
			}
			if (event.type == sf::Event::Closed)
				window.close();

		}
		
		m_board.draw(window);
		window.display();
	}
}



