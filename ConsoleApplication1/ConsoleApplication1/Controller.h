#include "Board.h"
#include <iostream>

class Controller
{
public:

	Controller() {}
	~Controller() {}

	void run();
	sf::Vector2f read_data();
};