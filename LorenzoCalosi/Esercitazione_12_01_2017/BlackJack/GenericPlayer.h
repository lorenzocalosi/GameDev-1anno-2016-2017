#include <string>

using namespace std;

class GenericPlayer : public Hand
{
    private:
        string _name;

    public:
        GenericPlayer();
        virtual bool isHitting() const = 0;
        bool isBusted() const;
        void bust() const;
        void printHand() const;
};
