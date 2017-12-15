
#include "Controller.h"



void Controller::run()
{
	Board board(read_data());

	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");

	sf::RectangleShape rect(sf::Vector2f(1,100));
	rect.setFillColor(sf::Color::Red);

	while (window.isOpen())
	{


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		
		window.clear();
		window.draw(rect);
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


