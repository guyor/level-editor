#include "Board.h"
#include <iostream>

class Controller
{
public:

	Controller() {}
	~Controller() {}

	void run();
	
private:

	bool m_read = true;
	bool m_out = false;
};