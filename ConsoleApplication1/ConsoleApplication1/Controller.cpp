
#include "Controller.h"



void Controller::run()
{
	sf::RenderWindow window(sf::VideoMode(801, 601), "SFML works!");
	
	sf::Vector2f size(15, 15);
	Board board(size,window);
	
	

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{
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


