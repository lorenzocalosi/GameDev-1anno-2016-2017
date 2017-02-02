#include <vector>

#include "Card.hpp"

using namespace std;

class Hand
{
    protected:
        vector< Card > _cards;

    public:
        ~Hand();
        Hand();
        void add(const Card &card);
        void clear();
        int getTotal() const;
};
