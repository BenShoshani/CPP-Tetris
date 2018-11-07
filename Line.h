#ifndef _LINE_H
#define _LINE_H
#include "Shape.h"


class Line: public Shape
{
private:
	bool isColumn = false;
	Point* holes = NULL;
public:
	enum SIZE{ROWS=1,COLS=4};
	Line(Point start,char sign): Shape(start,(int)ROWS,(int)COLS,sign) {}
	~Line() {};
	
	void chaeckMoves(bool * left, bool * right, bool * down, Board& board);
	void move(Point::directions direction,Board* board);
	void rotateColumnToLeft();
	void rotateLine();
	void rotateColumnToRight();
	bool chaeckMovesToDown(Board* board);
	void explode(Board& board) {};
	Point* getHoles() { return holes; }

};

#endif


