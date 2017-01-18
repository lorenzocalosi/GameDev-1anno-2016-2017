#include "Hand.h"

Hand::Hand()
{

}

void Hand::Add(const Card &card)
{
    _cards.push_back(card);
}

void Hand::clear()
{
    _cards.clear();
}

int Hand::getTotal() const
{
    int total = 0;
    int aces = 0;
    for(int i = 0; i<_cards.size(); i++)
    {
        if(_cards[i].getValue() == A)
        {
            aces++;
        }
        else
        {
            total += _cards[i].getValue();
        }
    }
    for(int i = 0; i <= aces; i++)
    {
        if(total + 11 > 21)
        {
            total += 1;
        }
        else
        {
            total += 11;
        }
    }
    return total;
}
