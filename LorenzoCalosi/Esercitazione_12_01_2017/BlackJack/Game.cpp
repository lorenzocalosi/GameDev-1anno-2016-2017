#include "Game.h"

Game::Game()
{
    int players;
    cout << "How many players? (Max 7)" << endl;
    do
    {
        cin >> players;
    }
    while(players <= 0 && players > 7);
}

void Game::play()
{
    for(int i = 0; i < _players.size(); i++)
    {

    }
}
