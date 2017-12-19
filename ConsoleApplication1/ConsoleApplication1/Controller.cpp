
#include "Controller.h"


void Controller::run()
{
	unsigned int x, y;
	std::cin >> x >> y;
	
	sf::RenderWindow window(sf::VideoMode(((y + 1) * P_SIZE) , x * P_SIZE), "SFML works!");
	
	sf::Vector2f size((float)x, (float)y);
	Board board(size,window);
	bool pressed = false;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch(event.type)
			{
			case sf::Event::Closed:
					window.close();
					break;
			case sf::Event::MouseButtonReleased:
				board.mouse_button_released(event);
				break;

			}
			if (event.type == sf::Event::Closed)
				window.close();

		}
		
		window.clear();
		board.draw_new_page(window, (size));
		
		window.display();
	}
}

sf::Vector2f Controller::read_data()
{
	sf::Vector2f boardsize;
	std::cout << "please enter number of rows ";
	std::cin >> boardsize.x;
	std::cout << "please enter number of columns ";
	std::cin >> boardsize.y;
	return boardsize;
}


