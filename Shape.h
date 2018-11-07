#ifndef _SHAPE_H
#define _SHAPE_H
class Board;
#include "Point.h"
#include"Board.h"
#include <iostream>
using namespace std;

class Shape
{
private:
	int rows, cols;
	Point **body;
	char sign;
public:
	enum eShapes { SQUARE, LINE, BOMB, JOKER ,L,PLUS,Z};
	enum DIR{ROTATER=1,ROTATEL=-1};
	void putCoord(Point start);
	bool checkLimX(Point::directions keyPressed,int rows,int cols);
	bool checkLimY(int rows,int cols);
	void deleteShape(int rows);
	Point ** getBody();
	char getSign() { return sign; };
	void draw(int rows, int cols, Point* holes);
	void setRow(int x) { rows = x; };
	void setCol(int y) { cols = y; };
	int getRows() { return rows; };
	int getCols() { return cols; };
	
	virtual void chaeckMoves(bool * left, bool * right, bool * down, Board& board) =0;
	virtual void move(Point::directions direction, Board* board) =0;
	virtual void explode(Board& board) =0;
	virtual bool chaeckMovesToDown(Board* board)=0;
	virtual Point* getHoles() = 0;
	Shape() {};
	Shape(Point start, int rows, int cols, char sign);
	

};
#endif 



