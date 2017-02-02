#include "House.hpp"

House::House()
{

}

virtual bool House::isHitting() const
{
    return (this->getTotal() <= 16 && !isBusted());
}

void House::flipFirstCard()
{
    if (!_cards.empty()) {
        _cards[0].flip();
    }
}
