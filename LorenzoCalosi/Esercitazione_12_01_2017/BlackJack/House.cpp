#include "House.h"

House::House()
{

}

virtual bool House::isHitting() const
{
    if( this->getTotal() <= 15 )
    {
        return true;
    }
    return false;
}

void House::flipFirstCard()
{
    _cards[0].flip();
}
