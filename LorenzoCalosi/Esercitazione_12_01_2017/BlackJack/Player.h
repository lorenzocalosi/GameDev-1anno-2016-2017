#include "GenericPlayer.h"

class Player : public GenericPlayer
{
    public:
        Player();
        virtual bool isHitting() const;
        void win() const;
        void lose() const;
        void push() const;
};
