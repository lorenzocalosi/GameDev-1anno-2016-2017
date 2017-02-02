#include "GenericPlayer.hpp"

class House : public GenericPlayer
{
    public:
        //TODO: Change this into two costructors, one with a string variable, one empty.
        House();
        ~House();
        virtual bool isHitting() const;
        void flipFirstCard();
};
