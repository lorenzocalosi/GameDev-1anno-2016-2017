#include "Card.hpp"

Card::Card()
{
    _rank = A;
    _suit = S;
}

Card::Card(Rank r, Suit s)
{
    _rank = r;
    _suit = s;
}

int Card::getValue()
{
    return _rank;
}

void Card::flip()
{
    _isFaceUp = !_isFaceUp;
}

void Card::printCard()
{
    if(_isFaceUp)
    {
        switch(_rank)
        {
            case A:
                cout << 'A';
                break;
            case J:
                cout << 'J';
                break;
            case Q:
                cout << 'Q';
                break;
            case K:
                cout << 'K';
                break;
            default:
                cout << _rank;
        }
        switch(_suit)
        {
            case S:
                cout << 's';
                break;
            case C:
                cout << 'c';
                break;
            case D:
                cout << 'd';
                break;
            case H:
                cout << 'h';
                break;
        }
    }
    else
    {
        cout << "XX";
    }
}
