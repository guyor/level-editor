#pragma once

enum Toolbar_t { PACMAN, DEMON, COOKIE, WALL, SAVE, ERASE, CLEAR, RED, BLUE, GREEN };


class Icon 
{
public:

	void setShape(const Toolbar_t shape) { m_shape = shape; };
	void setcolor(const Toolbar_t color) { m_color = color; };

private:
	Toolbar_t m_shape;
	Toolbar_t m_color;
};