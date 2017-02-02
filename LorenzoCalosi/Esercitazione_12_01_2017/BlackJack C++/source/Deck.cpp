#include "Deck.hpp"
#include "Card.hpp"
#include <algorithm>

Deck::Deck()
{
    _cards.reserve(52);
    this->populate();
    this->shuffle();
}

void Deck::populate()
{
    for(int suit = Card::Rank::A; rank < Card::Rank::K; suit++)
    {
        for(int rank = Card::Suit::S; rank < Card::Suit::H; rank++)
        {
            this->add(new Card(rank,suit));
        }
    }
}

void Deck::shuffle()
{
    random_shuffle( _cards.begin(), _cards.end() );
}

void Deck::deal(Hand& hand)
{
    if (!_cards.empty())
    {
        hand.add(_cards.back());
        _cards.pop_back()
    }
    else
    {
        cout << "Out of cards! Unable to deal."
    }
}

void Deck::additionalCards(GenericPlayer& genericPlayer)
{
    cout << endl;
    while(genericPlayer.isHitting() && !genericPlayer.isBusted())
    {
        this->deal(genericPlayer);
        genericPlayer.printHand();

        if(genericPlayer.isBusted())
        {
            genericPlayer.bust();
        }
    }
}
