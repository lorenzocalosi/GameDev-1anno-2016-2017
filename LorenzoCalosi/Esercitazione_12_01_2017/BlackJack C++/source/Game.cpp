#include "Game.hpp"

Game::Game(vector<string> playerNames)
{
    _house = House("House");
    for(int i = 0; i < playerNames.size(); i++)
    {
        _players.push_back(Player(playerNames[i]));
    }
}

Game::~Game()
{}

void Game::playRound()
{
    vector<Player>::iterator playerIterator;

    // Preparo il mazzo
    _deck.populate();
    _deck.shuffle();

    // Assegno 2 carte a tutti i giocatori e al banco
    for(int i = 0; i < 2; i++)
    {
        for(playerIterator = _players.begin(); playerIterator != _players.end(); playerIterator++)
        {
            _deck.deal(*playerIterator);
        }
        _deck.deal(_house);
    }

    // Copro la prima carta del banco
    _house.flipFirstCard();

    // Mostro le carte a tutti
    for(playerIterator = _players.begin(); playerIterator != _players.end(); playerIterator++)
    {
        (*playerIterator).printHand();
    }

    // Dai le carte addizionali ai giocatori
    for(playerIterator = _players.begin(); playerIterator != _players.end(); playerIterator++)
    {
        _deck.additionalCards(*playerIterator);
    }

    // Giro la carta del banco
    _house.flipFirstCard();

    // Dai le carte addizionali al banco
    _deck.additionalCards(_house);

    // Determino l'esito del match
        // Se il banco ha sballato
            // Tutti i giocatori che non hanno sballato vincono
        // Altrimenti
            // I giocatori che hanno il punteggio più alto di quello del banco vincono
            // I giocatori che hanno il punteggio più basso di quello del banco perdono
            // I giocatori che hanno lo stesso punteggio del banco pareggiano
    if(_house.isBusted())
    {
        for(playerIterator = _players.begin(); playerIterator != _players.end(); playerIterator++)
        {
            if(!(*playerIterator).isBusted())
            {
                playerIterator->win();
            }
        }
    }
    else
    {
        for(playerIterator = _players.begin(); playerIterator != _players.end(); playerIterator++)
        {
            if(!(*playerIterator).isBusted())
            {
                if(playerIterator->getTotal() > _house.getTotal())
                {
                    playerIterator->win();
                }
                else if(playerIterator->getTotal() < _house.getTotal())
                {
                    playerIterator->lose();
                }
                else
                {
                    playerIterator->push();
                }
            }

        }
    }

    // Rimuovi tutte le care dal banco e dai giocatori
    for(playerIterator = _players.begin(); playerIterator != _players.end(); playerIterator++)
    {
        playerIterator->clear();
    }
    _house.clear();
}
