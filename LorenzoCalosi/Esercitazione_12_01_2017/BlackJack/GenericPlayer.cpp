#include "GenericPlayer.h"
#include <iostream>

GenericPlayer::GenericPlayer()
{
    cout << "Insert this player's name:" << endl;
    cin >> _name;
}

bool isBusted() const
{
    if(this->getTotal() > 21)
    {
        return true;
    }
    return false;
}

void bust() const
{
    cout << "This player is bust!" << endl;
    cout << "Current hand value: " << this->getTotal() << endl;
}

void printHand() const
{
    for(int i = 0; i<_cards.size(); i++)
    {
        cout << "Card " << i << ": " << _cards[i].printCard() << endl;
    }
}
