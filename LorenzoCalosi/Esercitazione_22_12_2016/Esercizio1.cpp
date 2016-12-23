#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string>
#include <vector>

using namespace std;

class Entity
{
    int _health;
    int _will;
    int _attack;
    int _taunt;
    string _name;
    public:
        Entity(const string &entityType);
        void dealDamage(const char &damageType, Entity &enemy, const int &randValue=0) const;
        void takeDamage(const char &damageType, const int &damageValue);
        bool isAlive() const;
        void printStats(const int index = 0) const;
};

Entity::Entity(const string &entityType)
{
    if(entityType == "Belmont")
    {
        _health = 100;
        _will = 100;
        _attack = 10;
        _taunt = 10;
        _name = "Simon Belmont";
    }
    else if(entityType == "Dracula")
    {
        _health = 50;
        _will = 50;
        _attack = 20;
        _taunt = 20;
        _name = "Lord Dracula";
    }
    else if(entityType == "Servant")
    {
        _health = 12;
        _will = 30;
        _attack = 12;
        _taunt = 10;
        _name = "Servant";
    }
    else if(entityType == "Spectre")
    {
        _health = 100;
        _will = 12;
        _attack = 2;
        _taunt = 20;
        _name = "Spectre";
    }
}

void Entity::dealDamage(const char &damageType, Entity &enemy, const int &randValue) const
{
    if(damageType == 'h')
    {
        enemy.takeDamage('h',_attack+randValue);
    }
    else if(damageType == 'w')
    {
        enemy.takeDamage('w',_taunt+randValue);
    }
    return;
}

void Entity::takeDamage(const char &damageType, const int &damageValue)
{
    if(damageType == 'h')
    {
        _health -= damageValue;
    }
    else if(damageType == 'w')
    {
        _will -= damageValue;
    }
    return;
}

bool Entity::isAlive() const
{
    if(_health > 0 && _will > 0)
    {
        return true;
    }
    return false;
}

void Entity::printStats(const int index) const
{
    if(index!=0)
    {
        cout << _name << " " << index << endl;
    }
    else
    {
        cout << _name << endl;
    }
    cout << "Health: " << _health << endl;
    cout << "Will: " << _will << endl;
    cout << endl;
    return;
}

void rest(Entity &belmont);
bool battle(Entity &belmont, const int &draculaChance = 0);
bool hunt(Entity &belmont, int &draculaChance);
void attack(const char &attackType, Entity &attacker, Entity &target);
int playerSelection(const int &max, const int &min = 0);

void rest(Entity &belmont)
{
    system("CLS");
    int healingChance = rand()%9;
    if(healingChance <= 2)
    {
        cout << "While resting you run into an enemy!" << endl;
        battle(belmont);
    }
    else
    {
        int randomValue = rand()%6+5;
        cout << "You spend a bit of time loitering." << endl;
        belmont.takeDamage('h', -randomValue);
        randomValue = rand()%6+5;
        belmont.takeDamage('w', -randomValue);
    }
    return;
}

int playerSelection(const int &max, const int &min)
{
    int choice;
    do
    {
        cin >> choice;
    }
    while(choice >= max && choice <= min);
    return choice;
}

void attack(const char &attackType, Entity &attacker, Entity &target)
{
    int randValue = rand()%5;
    attacker.dealDamage(attackType, target, randValue);
    return;
}

bool battle(Entity &belmont, const int &draculaChance)
{
    int isDracula = rand()%9+1;
    bool draculaAppear = false;
    int selection;
    int monsterChoice;
    int deadEnemies = 0;
    char attackType;
    vector<Entity> enemies;
    bool battleContinues = true;
    if(isDracula <= draculaChance)
    {
        cout << "IT'S DRACULA!!!" << endl;
        enemies.push_back(Entity("Dracula"));
        draculaAppear = true;
    }
    else
    {
        int enemyRand = rand()%2;
        if(enemyRand == 1)
        {
            enemies.push_back(Entity("Servant"));
            enemies.push_back(Entity("Servant"));
            enemies.push_back(Entity("Servant"));
        }
        else
        {
            enemies.push_back(Entity("Spectre"));
            enemies.push_back(Entity("Spectre"));
            enemies.push_back(Entity("Spectre"));
        }
    }
    do
    {
        cout << "Your stats: " << endl;
        belmont.printStats();
        cout << "Your opponents stats: " << endl;
        for(int i = 0; i<enemies.size(); i++)
        {
            if(enemies[i].isAlive())
            {
                if(enemies.size()==1)
                {
                    enemies[i].printStats();
                }
                else
                {
                    enemies[i].printStats(i+1);
                }
            }
            else
            {
                cout << "** ENEMY SLAIN **" << endl;
            }
        }
        cout << endl << "What will you do?\n1.Attack them with your whip.\n2.Taunt them!\nYour selection:";
        selection = playerSelection(2);
        switch (selection)
        {
            case 1:
                attackType = 'h';
                break;
            case 2:
                attackType = 'w';
                break;
        }
        deadEnemies = 0;
        for(int i = 0; i<enemies.size(); i++)
        {
            if(enemies[i].isAlive())
            {
                attack(attackType, belmont, enemies[i]);
                monsterChoice = rand()%2;
                if(monsterChoice == 0)
                {
                    attack('h',enemies[i],belmont);
                }
                else if(monsterChoice == 1)
                {
                    attack('w',enemies[i],belmont);
                }
            }
            if(!enemies[i].isAlive())
            {
                deadEnemies++;
            }
        }
        if(!belmont.isAlive()||deadEnemies == enemies.size())
        {
            battleContinues = false;
        }
        system("CLS");
    }
    while(battleContinues);
    if(draculaAppear && belmont.isAlive())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool hunt(Entity &belmont, int &draculaChance)
{
    system("CLS");
    cout << "You keep looking for Dracula, and an enemy appears!" << endl;
    bool draculaAppear = battle(belmont, draculaChance);
    if(!draculaAppear)
    {
        draculaChance++;
    }
    return draculaAppear;
}

int main()
{
    Entity belmont("Belmont");
    int draculaChance = 0;
    int selection;
    bool continueGame = true;
    bool victory;
    srand (time(NULL));
    cout << "You are the legendary vampire hunter Simon Belmont! Your hunt for the evil Lord Dracula is on!\n";
    do
    {
        cout << "Your stats:" << endl;
        belmont.printStats();
        cout << "What will you do?\n1.Keep looking for Dracula.\n2.Rest awhile\n\nMake a selection:";
        selection = playerSelection(2);
        switch(selection)
        {
            case 1:
                continueGame = !hunt(belmont, draculaChance);
                break;
            case 2:
                rest(belmont);
                break;
        }
        if(belmont.isAlive())
        {
            cout << "You survive this ordeal!" << endl;
        }
        if(!belmont.isAlive())
        {
            continueGame = false;
            cout << "The opponent overwhelms you!" << endl;
        }
    }
    while(continueGame);
    if(belmont.isAlive())
    {
        cout << "You've done it! You've slain Lord Dracula!" << endl;
    }
    else
    {
        cout << "You've failed your quest, and everything is lost." << endl;
    }
    system("PAUSE");
}
