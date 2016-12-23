#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>

using namespace std;

const int ROWS = 10;
const int COLUMNS = 10;
const int N_BATTLESHIP = 2;
const int N_CARRIER = 1;
const int N_CRUISER = 3;
const int L_BATTLESHIP = 3;
const int L_CARRIER = 4;
const int L_CRUISER = 2;

enum Value {EMPTY, MISS, SHIP = 5, CLOSE = 8, HIT};

struct Position
{
	int x;
	int y;
};

class GameBoard
{
	vector< vector<Value> > boardPositions;

	public:
		GameBoard();
		bool placePart(const Position &position);
		bool destroyPart(const Position &position);
		bool isPart(const Position &position) const;
		bool isClose(const Position &position) const;
};

struct Ship
{
	string name;
	int length;
	int quantity;
};

Position makePosition(const Position lastPosition);
bool insertShip(GameBoard &board, const Position &position);
bool fireAttack(GameBoard &board, const Position &position);
void getPlayerMove(GameBoard &board);
void getComputerMove(GameBoard &board);
void shipPlacement(GameBoard &board, const int &shipLength);
int convertToInt(const char &y);
char convertToChar(const int &y);

int main()
{

}

Position makePosition(const Position lastPosition)
{
	Position newPosition;
	int x;
	int y;
	char charY;
	if(lastPosition.x == -1 && lastPosition.y == -1)
	{
		do
		{
			cout << "Insert the piece's position on X (1,2..): " << endl;
			cin >> x;
		}
		while(x < COLUMNS && x >= 0);
		do
		{
			cout << "Insert the piece's position on Y (1,2..): " << endl;
			cin >> charY;
			y = convertToInt(charY);
		}
		while(y < ROWS && y >= 0);
		newPosition.x = x;
		newPosition.y = y;
		return newPosition;
	}
	else
	{
		do
		{
			cout << "Insert the piece's position on X (A,B..) adjacent to the last piece's position (" << convertToChar(lastPosition.x) << "):" << endl;
			cin >> x;
		}
		while(x < COLUMNS && x >= 0 && (x == lastPosition.x+1 || x == lastPosition.x-1));
		do
		{
			cout << "Insert the piece's position on Y (1,2..) adjacent to the last piece's position (" << lastPosition.y << "): " << endl;
			cin >> charY;
			y = convertToInt(charY);
		}
		while(y < ROWS && y >= 0 && (y == lastPosition.y+1 || y == lastPosition.y-1));
		newPosition.x = x;
		newPosition.y = y;
		return newPosition;
	}
}

void shipPlacement(GameBoard &board, const int &shipLength)
{
	Position lastPosition;
	Position newPosition;
	for(int i = 0; i < N_CRUISER; i++)
	{
		cout << "Place Cruiser N" << i+1 << " . Length: " << L_CRUISER << endl;
		lastPosition.x = -1;
		lastPosition.y = -1;
		for(int j = 0; j < L_CRUISER; j++)
		{
			cout << "Piece number " << j+1 << " out of " << L_CRUISER endl;
			do
			{
				newPosition = makePosition(lastPosition);
				if(board.isPart(newPosition))
				{
					cout << "Illegal placement, you already placed a piece there!" << endl;
				}
				else
				{
					lastPosition.x = newPosition.x;
					lastPosition.y = newPosition.y;
				}
			}
			while(board.isPart(newPosition)&&);

		}
	}
}

int convertToInt(const char &y)
{
	switch(y)
	{
		case 'L':
			return 0;
			break;
		case 'I':
			return 1;
			break;
		case 'H':
			return 2;
			break;
		case 'G':
			return 3;
			break;
		case 'F':
			return 4;
			break;
		case 'E':
			return 5;
			break;
		case 'D':
			return 6;
			break;
		case 'C':
			return 7;
			break;
		case 'B':
			return 8;
			break;
		case 'A':
			return 9;
			break;
		default:
			return -1;
			break;
	}
}

char convertToChar(const int &y)
{
	switch(y)
	{
		case 0:
			return 'L';
			break;
		case 1:
			return 'I';
			break;
		case 2:
			return 'H';
			break;
		case 3:
			return 'G';
			break;
		case 4:
			return 'F';
			break;
		case 5:
			return 'E';
			break;
		case 6:
			return 'D';
			break;
		case 7:
			return 'C';
			break;
		case 8:
			return 'B';
			break;
		case 9:
			return 'A';
			break;
		default:
			return 'X';
			break;
	}
}

GameBoard::GameBoard()
{
	for(int i = 0; i < ROWS; i++)
	{
		for(int j = 0; j < COLUMNS; j++)
		{
			boardPositions[i][j] = EMPTY;
		}
	}
}

bool GameBoard::placePart(const Position &position)
{
	if(!this->isPart(position)&&!this->isClose(position))
	{
		boardPositions[position.x][position.y] = SHIP;
		return true;
	}
	return false;
}

bool GameBoard::destroyPart(const Position &position)
{
	if(this->isPart(position))
	{
		boardPositions[position.x][position.y] = HIT;
		return true;
	}
	boardPositions[position.x][position.y] = MISS;
	return false;
}

bool GameBoard::isPart(const Position &position) const
{
	if(boardPositions[position.x][position.y] == SHIP)
	{
		return true;
	}
	return false;
}

bool GameBoard::isClose(const Position &position) const
{
	if(boardPositions[position.x][position.y] == CLOSE)
	{
		return true;
	}
	return false;
}