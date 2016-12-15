#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string>
#include <vector>

using namespace std;

const unsigned int STARTING_TANKS = 5;
const unsigned int MAX_VALOR = 100;
const string VICTORY_MESSAGE = "Congratulations, you nazi bastard! You win!\n";
const string LOSE_MESSAGE = "You lose! You disgrace our powerful Reich!\n";
const string CONTINUE_MESSAGE = "Do you wish to play again? (y/n)\n";
const string MISSION_SELECT = "Choose a mission\n1.Patrol the surroundings\n2.Attack the allies base\n3.Repair your units\n\nYour selection:";

enum missionChoice {PATROL = 1, ATTACK, REFILL};

class Tank
{
    int _health;
    int _fuel;
    int _ammo;
    string _name;

    public:
        Tank();
        int Patrol(const int &distance);
        int Attack(const int &strength);
        void Refill(const int &repair);
        void PrintSituation();
        bool isAlive();
};

void selectMission(vector<Tank> &tankArray, int &valor);
void printTeam(vector<Tank> &tankArray, const int &valor);
bool checkAlive(vector<Tank> &tankArray);
void initializeTanks(vector<Tank> &tankArray);
char yesNo();
void printMessage(const string &message);
char gameOver(vector<Tank> &tankArray, const int &valor);

int main()
{
    srand (time(NULL));
    char gameState = 'N';
    char continueGame = 'n';
    bool playGame = true;
    int valor = 0;
    vector<Tank> tankArray;
    do
    {
        playGame = true;
        gameState = 'N';
        valor = 0;
        initializeTanks(tankArray);
        do
        {
            printTeam(tankArray, valor);
            selectMission(tankArray, valor);
            system("CLS");
            gameState = gameOver(tankArray, valor);
            if(gameState == 'V' || gameState == 'L'){
                playGame = false;
            }
        }
        while(playGame);
        printTeam(tankArray, valor);
        if(gameState=='V'){
            printMessage(VICTORY_MESSAGE);
        }
        else if(gameState=='L'){
            printMessage(LOSE_MESSAGE);
        }
        printMessage(CONTINUE_MESSAGE);
        continueGame = yesNo();
    }
    while(continueGame=='y');
    return 1;
}

void selectMission(vector<Tank> &tankArray, int &valor)
{
    int input;
    printMessage(MISSION_SELECT);
    do
    {
        cin >> input;
    }
    while(input<1||input>3);
    for(int i=0;i<tankArray.size();i++)
    {
        switch(input)
        {
            case PATROL:
                valor += tankArray[i].Patrol(rand()%3+2);
                break;
            case ATTACK:
                valor += tankArray[i].Attack(rand()%3+2);
                break;
            case REFILL:
                tankArray[i].Refill(rand()%3+2);
                break;
        }
    }
    if(input==REFILL)
    {
        valor-=5;
    }
    return;
}

bool checkAlive(vector<Tank> &tankArray)
{
    for(int i=0;i<tankArray.size();i++)
    {
        if(tankArray[i].isAlive()){
            return true;
        }
    }
    return false;
}

void printTeam(vector<Tank> &tankArray, const int &valor)
{
    cout << "YOUR VALOR: " << valor << endl;
    for(int i=0;i<tankArray.size();i++)
    {
        cout << "Tank " << i+1 << ": " << endl;
        tankArray[i].PrintSituation();
    }
    return;
}

void initializeTanks(vector<Tank> &tankArray)
{
    for(int i=0;i<STARTING_TANKS;i++)
    {
        tankArray.push_back(Tank());
    }
    return;
}

char yesNo()
{
    char input;
    do
    {
        cin >> input;
    }
    while(input!='y'&&input!='n');
    return input;
}

void printMessage(const string &message)
{
    cout << message;
    return;
}

char gameOver(vector<Tank> &tankArray, const int &valor)
{
    if(!checkAlive(tankArray))
    {
        return 'L';
    }
    else if(valor>=MAX_VALOR)
    {
        return 'W';
    }
    else
    {
        return 'N';
    }
}

Tank::Tank()
{
    _health = 100;
    _fuel = 100;
    _ammo = 100;
    _name = "Tiger Panzer";
}

int Tank::Patrol(const int &distance)
{
    if(this->isAlive())
    {
        _health -= distance*2;
        _fuel -= distance*8;
        _ammo -= distance*2;
        return 1;
    }
    return 0;
}

int Tank::Attack(const int &strength)
{
    if(this->isAlive())
    {
        _health -= strength*7;
        _fuel -= strength*3;
        _ammo -= strength*7;
        return 2;
    }
    return 0;
}

void Tank::Refill(const int &repair)
{
    if(this->isAlive())
    {
        _health += repair*5;
        _fuel += repair*5;
        _ammo += repair*5;
    }
    return;
}

void Tank::PrintSituation()
{
    if(!this->isAlive())
    {
        cout << "**TANK DESTROYED**" << endl;
    }
    else
    {
        cout << "Name: " << _name << endl;
        cout << "Health: " << _health << endl;
        cout << "Fuel: " << _fuel << endl;
        cout << "Ammo: " << _ammo << endl;
    }
}

bool Tank::isAlive()
{
    return (_health>0&&_ammo>0&&_fuel>0)? true : false;
}
