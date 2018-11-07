#ifndef _SQUARE_H
#define _SQUARE_H
#include "Shape.h"


class Square : public Shape
{
	Point* holes = NULL;
public:
	enum SIZE { ROWS = 2, COLS = 2 };
	Square(Point start, char sign) : Shape(start, (int)ROWS, (int)COLS, sign) {}
	~Square() {};

	void chaeckMoves(bool * left, bool * right, bool * down, Board& board);
	void move(Point::directions direction,Board* board);
	bool chaeckMovesToDown(Board* board);
	void explode(Board& board) {};
	Point* getHoles() { return holes;}

};
#endif


