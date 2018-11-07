#include "Line.h"

void Line::chaeckMoves(bool * left, bool * right, bool * down, Board& board)
{
	Point maxRight, minLeft, maxDown;
	Point ** tempBody = (*this).getBody();
	maxRight = minLeft = maxDown = tempBody[0][0];
	string* tempBoard = board.getGameBoard();
	if (isColumn)
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				if (tempBoard[tempBody[i][j].getY()][tempBody[i][j].getX() + 1] != Board::CLEAR && (*right))
					*right = false;
				if (tempBoard[tempBody[i][j].getY()][tempBody[i][j].getX() - 1] != Board::CLEAR && (*left))
					*left = false;
				if (maxDown.getY() < tempBody[i][j].getY())
					maxDown = tempBody[i][j];
			}
		}
		if (tempBoard[maxDown.getY() + 1][maxDown.getX()] != Board::CLEAR && (*down))
			*down = false;
	}
	else
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				if (minLeft.getX() > tempBody[i][j].getX())
					minLeft = tempBody[i][j];
				if (maxRight.getX() < tempBody[i][j].getX())
					maxRight = tempBody[i][j];
				if (tempBoard[tempBody[i][j].getY() + 1][tempBody[i][j].getX()] != Board::CLEAR && (*down))
					*down = false;
			}
		}
		if (tempBoard[maxRight.getY()][maxRight.getX() + 1] != Board::CLEAR && (*right))
			*right = false;
		if (tempBoard[minLeft.getY()][minLeft.getX() - 1] != Board::CLEAR && (*left))
			*left = false;
	}
	tempBody = NULL;
	delete[] tempBody;
}
void Line::move(Point::directions direction, Board* board)
{
	Point** tempBody = (*this).getBody();
	char sign = this->getSign();
	if (direction == Point::UP)
	{
		if (isColumn)
		{
			if (tempBody[0][0].getX() < 3)
				rotateColumnToRight();
			else
				rotateColumnToLeft();
		}
		else
			rotateLine();
		for (int i = COLS - 1; i >= 0; i--)
		{
			tempBody[ROWS - 1][i].draw(sign);
		}

	}
	else
	{
		for (int i = COLS - 1; i >= 0; i--)
		{
			tempBody[ROWS - 1][i].draw(' ');
			tempBody[ROWS - 1][i].move(direction);

		}
		for (int i = COLS - 1; i >= 0; i--)
		{
			tempBody[ROWS - 1][i].draw(sign);
		}
	}
	tempBody = NULL;
	delete[] tempBody;
}
void Line::rotateColumnToRight()
{
	int index = 0;
	Point** tempBody = this->getBody();
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = COLS - 1; j >= 0; j--)
		{
			tempBody[i][j].draw(' ');
			tempBody[i][j].setX(tempBody[i][j].getX() + index);
			tempBody[i][j].setY(tempBody[i][j].getY() + index);
			index++;
		}
	}
	isColumn = (!isColumn);
	tempBody = NULL;
	delete[] tempBody;
}
void Line::rotateLine()
{
	int index = 0;
	Point** tempBody = this->getBody();
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = COLS - 1; j >= 0; j--)
		{
			tempBody[i][j].draw(' ');
			tempBody[i][j].setX(tempBody[i][j].getX() + index);
			tempBody[i][j].setY(tempBody[i][j].getY() - index);
			index++;
		}
	}
	isColumn = (!isColumn);
	tempBody = NULL;
	delete[] tempBody;
}
void Line::rotateColumnToLeft()
{
	int index = 0;
	Point** tempBody = this->getBody();
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = COLS - 1; j >= 0; j--)
		{
			tempBody[i][j].draw(' ');
			tempBody[i][j].setX(tempBody[i][j].getX() - index);
			tempBody[i][j].setY(tempBody[i][j].getY() + index);
			index++;
		}
	}
	isColumn = (!isColumn);
	tempBody = NULL;
	delete[] tempBody;
}
bool Line::chaeckMovesToDown(Board* board)
{
	Point maxDown;
	bool down = true;
	string* tempBoard = board->getGameBoard();
	Point** tempBody = this->getBody();

	if (isColumn)
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				if (maxDown.getY() < tempBody[i][j].getY())
					maxDown = tempBody[i][j];
			}
		}
		if (tempBoard[maxDown.getY() + 2][maxDown.getX()] != Board::CLEAR && (down))
			down = false;
	}
	else
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
			{
				if (tempBoard[tempBody[i][j].getY() + 2][tempBody[i][j].getX()] != Board::CLEAR && (down))
					down = false;
			}
		}
	}
	tempBoard = NULL;
	tempBody = NULL;
	delete[] tempBody;
	delete[] tempBoard;
	return down;
}

