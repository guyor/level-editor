
#include "Controller.h"


void Controller::run()
{
	sf::Vector2f size(m_x, m_y);

	sf::RenderWindow window(sf::VideoMode(((int)(m_board.getBoardSize().y + 1) * P_SIZE) , (int)m_board.getBoardSize().x * P_SIZE), "SFML works!");
	
	bool pressed = false;
	while (window.isOpen())
	{
		window.clear();
		m_board.draw(window);

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
		
		
		window.display();
	}
}



