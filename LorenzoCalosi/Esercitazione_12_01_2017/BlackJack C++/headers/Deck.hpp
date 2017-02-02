#include "Hand.hpp"
#include "GenericPlayer.hpp"

class Deck : public Hand
{
    public:
        Deck();
        ~Deck();
        void populate();
        void shuffle();
        void deal(Hand& hand);
        void additionalCards(GenericPlayer& genericPlayer);
};
