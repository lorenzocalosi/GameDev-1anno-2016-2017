#include "GenericPlayer.hpp"

class Player : public GenericPlayer
{
    public:
        //TODO: Change this into two constructors, one with a string variable, one empty.
        Player();
        ~Player()
        virtual bool isHitting() const;
        void win() const;
        void lose() const;
        void push() const;
};
