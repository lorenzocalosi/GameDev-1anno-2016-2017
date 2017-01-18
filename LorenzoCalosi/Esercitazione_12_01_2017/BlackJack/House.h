#include "GenericPlayer.h"

class House : public GenericPlayer
{
    public:
        House();
        virtual bool isHitting() const;
        void flipFirstCard();
};
