#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

enum space {HERO = 7, TRAP = 5, TREASURE = 1, EMPTY = 0};
enum direction {UP,RIGHT,DOWN,LEFT};

const int SIZEX = 5;
const int SIZEY = 5;

struct position
{
    int x;
    int y;
};

direction getUserInput();
void printBoard(const vector< vector<space> >& board);
int moveHero(vector< vector<space> >& board, position heroPosition);
bool checkValid(position newPosition);
int checkEnd(vector< vector<space> >& board, position newPosition, position oldPosition);
void generateBoard(vector< vector<space> >& board);
bool yesNo();

int main()
{
    int status;
    do
    {
        vector< vector<space> > board;
        generateBoard(board);
        position heroPosition;
        heroPosition.x = SIZEX/2;
        heroPosition.y = SIZEY/2;
        do
        {
            printBoard(board);
            status = moveHero(board, heroPosition);
        }
        while(!status);
        if(status==-1)
        {
            //lose
        }
        else if(status==1)
        {
            //win
        }
    }
    while(yesNo());
    return 1;
}

direction getUserInput()
{
    direction input;
    while (getch() != '\033') { // if the first value is esc
        getch(); // skip the [
        switch(getch()) { // the real value
            case 'A':
                input = UP;
                break;
            case 'B':
                input = DOWN;
                break;
            case 'C':
                input = RIGHT;
                break;
            case 'D':
                input = LEFT;
                break;
        }
        return input;
    }
}

int moveHero(vector< vector<space> >& board, position heroPosition)
{
    position newPosition;
    direction input;
    do
    {
        input = getUserInput();
        switch(input)
        {
            case UP:
                newPosition.y = heroPosition.y+1;
                break;
            case DOWN:
                newPosition.y = heroPosition.y-1;
                break;
            case LEFT:
                newPosition.x = heroPosition.x-1;
                break;
            case RIGHT:
                newPosition.x = heroPosition.x+1;
                break;
        }
    }
    while (checkValid(board,newPosition));
    return checkEnd(board,newPosition,heroPosition);
}

int checkEnd(vector< vector<space> >& board, position newPosition, position oldPosition)
{
    int returnValue;
    switch(board[newPosition.x][newPosition.y])
    {
        case TRAP:
            returnValue = -1;
            break;
        case TREASURE:
            returnValue = 1;
            break;
        case EMPTY:
            returnValue = 0;
            break;
    }
    board[newPosition.x][newPosition.y] = HERO;
    board[oldPosition.x][oldPosition.y] = EMPTY;
    return returnValue;
}

void generateBoard(vector< vector<int> >& board)
{
    //TODO
}

bool checkValid(position newPosition)
{
    if(newPosition.x>=0&&newPosition.x<SIZEX||newPosition.y>=0&&newPosition.y<SIZEY)
    {
        return true;
    }
    return false;
}

void printBoard(const vector< vector<space> >& board)
{
    //TODO
}
