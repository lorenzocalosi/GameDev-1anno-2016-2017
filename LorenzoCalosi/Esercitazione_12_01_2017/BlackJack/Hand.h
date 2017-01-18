#include <vector>

#include "Card.h"

using namespace std;

class Hand
{
    protected:
        vector< Card > _cards;

    public:
        Hand();
        void Add(const Card &card);
        void clear();
        int getTotal() const;
};
