#include "Square.h"

void Square::chaeckMoves(bool * left, bool * right, bool * down, Board& board)
{
	Point maxRight, minLeft, maxDown;
	Point** tempBody = this->getBody();
	maxRight = minLeft = maxDown = tempBody[0][0];
	string* tempBoard = board.getGameBoard();
	
	maxRight = maxDown = tempBody[ROWS - 1][COLS - 1];
	if (tempBoard[maxDown.getY() + 1][maxDown.getX()] != Board::CLEAR || tempBoard[maxDown.getY() + 1][maxDown.getX() - 1] != Board::CLEAR)
		*down = false;
	else
		*down = true;
	if (tempBoard[maxRight.getY()][maxRight.getX() + 1] != Board::CLEAR || tempBoard[maxRight.getY() - 1][maxRight.getX() + 1] != Board::CLEAR)
		*right = false;
	else
		*right = true;
	if (tempBoard[minLeft.getY()][minLeft.getX() - 1] != Board::CLEAR || tempBoard[minLeft.getY() + 1][minLeft.getX() - 1] != Board::CLEAR)
		*left = false;
	else
		*left = true;
	tempBoard = NULL;
	tempBody = NULL;
	delete[] tempBody;
	delete[] tempBoard;
}
void Square::move(Point::directions direction,Board* board)
{
	Point** tempBody = this->getBody();
	char sign = this->getSign();
	switch (direction)
	{
		case Point::DOWN:
		{
			for (int i = ROWS - 1; i >= 0; i--)
			{
				tempBody[0][i].draw(' ');
				tempBody[0][i] = tempBody[1][i];
				tempBody[0][i].draw(' ');
				tempBody[0][i].setY(tempBody[0][i].getY() + 1);
				tempBody[0][i].draw(sign);

			}
			for (int i = ROWS - 1; i >= 0; i--)
			{
				tempBody[1][i].move(direction);
				tempBody[1][i].draw(sign);
			}
			break;
		}
		case Point::LEFT:
		{

			for (int i = ROWS - 1; i >= 0; i--)
			{
				tempBody[i][1].draw(' ');
				tempBody[i][1] = tempBody[i][0];
			}
			for (int i = ROWS - 1; i >= 0; i--)
			{
				tempBody[i][0].move(direction);
				tempBody[i][0].draw(sign);
			}
			break;
		}
		case Point::RIGHT:
		{
			for (int i = ROWS - 1; i >= 0; i--)
			{
				tempBody[i][0].draw(' ');
				tempBody[i][0] = tempBody[i][1];
			}
			for (int i = ROWS - 1; i >= 0; i--)
			{
				tempBody[i][1].move(direction);
				tempBody[i][1].draw(sign);
			}
			break;
		}
		default:
		{
			for (int i = ROWS - 1; i >= 0; i--)
			{
				tempBody[0][i].draw(' ');
				tempBody[0][i] = tempBody[1][i];
			}
			for (int i = ROWS - 1; i >= 0; i--)
			{
				tempBody[1][i].move(Point::STAND);
				tempBody[1][i].draw(sign);
			}
			break;
		}
	}
	tempBody = NULL;
	delete[] tempBody;
}
bool Square::chaeckMovesToDown(Board* board)
{
	Point maxDown;
	bool down = true;
	string* tempBoard = board->getGameBoard();
	Point** tempBody = this->getBody();

	maxDown = tempBody[ROWS - 1][COLS - 1];
	if (tempBoard[maxDown.getY() + 2][maxDown.getX()] != Board::CLEAR || tempBoard[maxDown.getY() + 2][maxDown.getX() - 1] != Board::CLEAR)
		down = false;
	else
		down = true;

	tempBoard = NULL;
	tempBody = NULL;
	delete[] tempBoard;
	delete[] tempBody;
	return down;
}