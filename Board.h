#ifndef _BOARD_H
#define _BOARD_H
class Shape;
#include "Point.h"
#include"Shape.h"

class Board {
public:
	enum cellState { CLEAR = 0 };

private:
	static int score;
	static int droppedShapes;

	string* gameBoard;

	void printLimits();
	void createMenu();
	bool isLineFull(int y);
	void dropLine(int y);


public:
	Board();
	~Board();
	static void updateDroppedShape()
	{
		droppedShapes++;
		gotoxy(1, 0);
		cout << "dropped shapes: " << droppedShapes;
	}
	static void updateScore(int addScore)
	{
		gotoxy(1, 1);
		score += addScore;
		cout << "score: " << score;
	}

	void copyShapeToBoard(Shape* shape, Point* hols);
	string* getGameBoard() { return gameBoard; };
	void updateBoard(Shape* shape, int currShape);
	void dropColumn(int x, int y);
};

#endif