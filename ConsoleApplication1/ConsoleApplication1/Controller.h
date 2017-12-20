#include "Board.h"
#include <iostream>

class Controller
{
public:

	Controller():m_board()
	{
		m_x = m_board.getBoardSize().x;
		m_y = m_board.getBoardSize().y;
	}
	~Controller() {}

	void run();
	
private:
	float m_x;
	float m_y;
	Board m_board;
	
};