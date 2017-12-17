
#include "Controller.h"



void Controller::run()
{
	sf::RenderWindow window(sf::VideoMode(801, 601), "SFML works!");
	
	sf::Vector2f size(30, 30);
	size.x++;
	Board board(size,window);
	
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
			case sf::Event::MouseMoved :
				board.set_mouse(sf::Vector2i(event.mouseButton.x,event.mouseButton.y));
				board.draw_back_rect(window, board.get_mouse(), size);
				break;
			case sf::Event::MouseButtonReleased:
				board.set_mouse(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
				break;

			}
			if (event.type == sf::Event::Closed)
				window.close();

		}
		
		window.clear();
		board.draw(window, (size));
		
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


