#include "Deck.h"
#include <algorithm>

Deck::Deck()
{
    srand ( unsigned ( std::time(0) ) );
    this->populate();
}

void Deck::populate()
{
    for(int i = 0; i < 13; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            this->Add(new Card(i,j));
        }
    }
}

void Deck::shuffle()
{
    random_shuffle( _cards.begin(), _cards.end() );
}

void Deck::deal(Hand& hand)
{
    hand.Add(_cards.pop_back());
}

void Deck::additionalCards(GenericPlayer& genericPlayer)
{
    genericPlayer.printHand();
    while(genericPlayer.isHitting())
    {
        this->deal(genericPlayer);
        genericPlayer.printHand();
    }
}
