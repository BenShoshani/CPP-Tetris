#ifndef _JOKER_H
#define _JOKER_H
#include "Shape.h"

class Joker : public Shape
{
	Point* holes = NULL;
public:
	enum SIZE { ROWS = 1, COLS = 1 };
	Joker(Point start, char sign) : Shape(start, (int)ROWS, (int)COLS, sign) {}
	~Joker() {};

	void chaeckMoves(bool * left, bool * right, bool * down, Board& board);
	void move(Point::directions direction, Board* board);
	bool chaeckMovesToDown(Board* board);
	void explode(Board& board);
	Point* getHoles() { return holes; }
};

#endif