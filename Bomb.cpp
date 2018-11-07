#include "Bomb.h"

void Bomb::chaeckMoves(bool * left, bool * right, bool * down, Board& board)
{
	Point** tempBody = this->getBody();
	string* tempBoard = board.getGameBoard();

	if (tempBoard[tempBody[0][0].getY()][tempBody[0][0].getX() + 1] != Board::CLEAR)
		*right = false;
	if (tempBoard[tempBody[0][0].getY()][tempBody[0][0].getX() - 1] != Board::CLEAR)
		*left = false;
	if (tempBoard[tempBody[0][0].getY() + 1][tempBody[0][0].getX()] != Board::CLEAR)
		*down = false;

	tempBoard = NULL;
	tempBody = NULL;
	delete[] tempBody;
	delete[] tempBoard;
}
void Bomb::move(Point::directions direction,Board* board)
{
	Point** tempBody = this->getBody();
	tempBody[0][0].draw(' ');
	if (direction != Point::UP)
		tempBody[0][0].move(direction);
	else
		tempBody[0][0].move(Point::STAND);
	tempBody[0][0].draw(this->getSign());

	tempBody = NULL;
	delete[] tempBody;
	
}
bool Bomb::chaeckMovesToDown(Board* board)
{
	Point maxDown;
	bool down = true;
	Point** tempBody = this->getBody();
	string* tempBoard = board->getGameBoard();

	if (tempBoard[tempBody[0][0].getY() + 2][tempBody[0][0].getX()] != Board::CLEAR)
		down = false;
	
	tempBoard = NULL;
	tempBody = NULL;
	delete[] tempBody;
	delete[] tempBoard;
	return down;
}
void Bomb::explode(Board& board)
{
	Point** tempBody = this->getBody();
	string* tempBoard = board.getGameBoard();
	for (int i = tempBody[0][0].getY() - 1; i <= tempBody[0][0].getY() + 1; i++)
	{
		for (int j = tempBody[0][0].getX() - 1; j <= tempBody[0][0].getX() + 1; j++)
		{
			if (j > Point::LIMLEFT && j<Point::LIMRIGHT && i>Point::LIMUP && i < Point::LIMDOWN)
			{
				if (tempBoard[i][j] == '*')
					Board::updateScore(-50);
				tempBoard[i][j] = Board::CLEAR;
				gotoxy(j, i);
				cout << ' ';
				board.dropColumn(j, i);
			}
		}
	}
	tempBoard = NULL;
	tempBody = NULL;
	delete[] tempBody;
	delete[] tempBoard;
}