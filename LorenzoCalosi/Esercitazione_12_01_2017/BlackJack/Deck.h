#include "Hand.h"
#include "GenericPlayer.h"

class Deck : public Hand
{
    public:
        Deck();
        void populate();
        void shuffle();
        void deal(Hand& hand);
        void additionalCards(GenericPlayer& genericPlayer);
};
