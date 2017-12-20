#include "Board.h"
#include <iostream>

class Controller
{
public:

	Controller():m_board(){}
	~Controller() {}

	void run();
	
private:
	float m_x;
	float m_y;
	Board m_board;
	
};