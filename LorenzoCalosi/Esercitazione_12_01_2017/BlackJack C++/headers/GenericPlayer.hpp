#include <string>

using namespace std;

class GenericPlayer : public Hand
{
    private:
        string _name;

    public:
        //TODO: Change this into two costructors, one with a string variable, one empty.
        GenericPlayer();
        ~GenericPlayer();
        virtual bool isHitting() const = 0;
        bool isBusted() const;
        void bust() const;
        void printHand() const;
};
