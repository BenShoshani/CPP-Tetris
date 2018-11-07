#include "Z.h"

Z::Z(Point start, char sign) : Shape(start, (int)ROWS, (int)COLS, sign)
{
	holes = new Point[2];
	holes[0] = { 0,2 };
	holes[1] = { 1,0 };
	state = ZLEFT;
}
void Z::chaeckMoves(bool * left, bool * right, bool * down, Board& board)
{

	Point** tempBody = this->getBody();
	string* tempBoard = board.getGameBoard();

	if (state == ZLEFT)
	{
		Point leftCheck, downCheck, rightCheck;
		leftCheck = tempBody[0][0];
		rightCheck = downCheck = tempBody[ROWS - 1][COLS - 1];
		if (tempBoard[rightCheck.getY()][rightCheck.getX()+1] != Board::CLEAR || tempBoard[rightCheck.getY() - 1][rightCheck.getX()] != Board::CLEAR)
			*right = false;
		else
			*right = true;
		if (tempBoard[downCheck.getY() + 1][downCheck.getX()] != Board::CLEAR || tempBoard[downCheck.getY() + 1][downCheck.getX() - 1] != Board::CLEAR || tempBoard[downCheck.getY()][downCheck.getX() - 2] != Board::CLEAR)
			*down = false;
		else
			*down = true;
		if (tempBoard[leftCheck.getY()][leftCheck.getX() - 1] != Board::CLEAR || tempBoard[leftCheck.getY() + 1][leftCheck.getX()] != Board::CLEAR)
			*left = false;
		else
			*left = true;
	}

	else if (state == ZUP)
	{
		Point leftCheck, rightCheck, downCheck;
		rightCheck = tempBody[0][0];
		downCheck = leftCheck = tempBody[ROWS - 1][COLS - 1];
		if (tempBoard[rightCheck.getY()][rightCheck.getX() + 1] != Board::CLEAR || tempBoard[rightCheck.getY() + 1][rightCheck.getX()+1] != Board::CLEAR || tempBoard[rightCheck.getY() + 2][rightCheck.getX()] != Board::CLEAR)
			*right = false;
		else
			*right = true;
		if (tempBoard[downCheck.getY() + 1][downCheck.getX()] != Board::CLEAR || tempBoard[downCheck.getY()][downCheck.getX() + 1] != Board::CLEAR)
			*down = false;
		else
			*down = true;
		if (tempBoard[leftCheck.getY()][leftCheck.getX() - 1] != Board::CLEAR || tempBoard[leftCheck.getY() - 1][leftCheck.getX() - 1] != Board::CLEAR || tempBoard[leftCheck.getY() - 2][leftCheck.getX()] != Board::CLEAR)
			*left = false;
		else
			*left = true;
	}
	tempBoard = NULL;
	tempBody = NULL;
	delete[] tempBody;
	delete[] tempBoard;
}
void Z::move(Point::directions direction, Board* board)
{
	bool right, left, down;
	chaeckMoves(&left, &right, &down, *board);
	Point** tempBody = this->getBody();
	string* tempBoard = board->getGameBoard();
	char sign = this->getSign();
	switch (direction)
	{
	case Point::UP:
	{
		if (state == ZLEFT)
		{
			if (down && tempBoard[tempBody[0][0].getY() - 1][tempBody[0][0].getX() + 1] == Board::CLEAR && tempBoard[tempBody[0][0].getY()+2][tempBody[0][0].getX()] == Board::CLEAR && checkLimX(direction, ROWS, COLS) && checkLimY(ROWS, COLS))
			{
				for (int i = COLS - 1; i >= 0; i--)
				{
					for (int j = ROWS - 1; j >= 0;j--)
					{
						tempBody[j][i].draw(' ');
						tempBody[j][i].rotate90Point((float)tempBody[0][1].getX(), (float)tempBody[0][1].getY(), (int)ROTATER);
					}
				}
				state = STATES((int)(state + 1));
			}
		}
		else if (state == ZUP)
		{
			if (down && left && right && tempBoard[tempBody[0][0].getY() + 2][tempBody[0][0].getX() + 1] == Board::CLEAR && checkLimX(direction, ROWS, COLS) && checkLimY(ROWS, COLS))
			{
				for (int i = COLS - 1; i >= 0; i--)
				{
					for (int j = ROWS - 1; j >= 0;j--)
					{
						tempBody[j][i].draw(' ');
						tempBody[j][i].rotate90Point((float)tempBody[0][1].getX(), (float)tempBody[0][1].getY(), (int)ROTATEL);
					}
				}
				state = STATES((int)(state + 1));
			}
		}
		state = STATES((int)state % 2);
		break;
	}
	case Point::DOWN:
	{
		for (int i = COLS - 1; i >= 0; i--)
		{
			for (int j = ROWS - 1; j >= 0;j--)
				tempBody[j][i].draw(' ');
		}
		for (int i = COLS - 1; i >= 0; i--)
		{
			for (int j = ROWS - 1; j >= 0;j--)
				tempBody[j][i].move(direction);
		}
		draw(ROWS, COLS, holes);
		break;
	}
	case Point::LEFT:
	{
		for (int i = COLS - 1; i >= 0; i--)
		{
			for (int j = ROWS - 1; j >= 0;j--)
				tempBody[j][i].draw(' ');
		}
		for (int i = COLS - 1; i >= 0; i--)
		{
			for (int j = ROWS - 1; j >= 0;j--)
				tempBody[j][i].move(direction);
		}
		draw(ROWS, COLS, holes);
		break;
	}
	case Point::RIGHT:
	{
		for (int i = COLS - 1; i >= 0; i--)
		{
			for (int j = ROWS - 1; j >= 0;j--)
				tempBody[j][i].draw(' ');
		}
		for (int i = COLS - 1; i >= 0; i--)
		{
			for (int j = ROWS - 1; j >= 0;j--)
				tempBody[j][i].move(direction);
		}
		draw(ROWS, COLS, holes);
		break;
	}
	default:
	{
		for (int i = COLS - 1; i >= 0; i--)
		{
			for (int j = ROWS - 1; j >= 0;j--)
				tempBody[j][i].draw(' ');
		}
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLS; j++)
				tempBody[i][j].move(Point::STAND);
		}
		draw(ROWS, COLS, holes);
		break;
	}
	}
	tempBody = NULL;
	delete[] tempBody;
}
bool Z::chaeckMovesToDown(Board* board)
{
	bool down = true;
	string* tempBoard = board->getGameBoard();
	Point** tempBody = this->getBody();
	if (state == ZLEFT)
	{
		Point downCheck = tempBody[ROWS - 1][COLS - 1];
		if (tempBoard[downCheck.getY() + 2][downCheck.getX()] != Board::CLEAR || tempBoard[downCheck.getY() + 2][downCheck.getX() - 1] != Board::CLEAR || tempBoard[downCheck.getY() + 1][downCheck.getX() - 1] != Board::CLEAR || tempBoard[downCheck.getY() + 1][downCheck.getX() - 2] != Board::CLEAR)
			down = false;
		else
			down = true;

	}
	else if (state == ZUP)
	{
		Point downCheck = tempBody[ROWS - 1][COLS - 1];
		if (tempBoard[downCheck.getY() + 2][downCheck.getX()] != Board::CLEAR || tempBoard[downCheck.getY() + 1][downCheck.getX()] != Board::CLEAR || tempBoard[downCheck.getY()+1][downCheck.getX() + 1] != Board::CLEAR || tempBoard[downCheck.getY()][downCheck.getX() + 1] != Board::CLEAR)
			down = false;
		else
			down = true;
	}
	tempBoard = NULL;
	tempBody = NULL;
	delete[] tempBoard;
	delete[] tempBody;
	return down;
}