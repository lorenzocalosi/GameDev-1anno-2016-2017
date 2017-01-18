#include "Deck.h"
#include "House.h"
#include "Player.h"
#include <vector>

class Game
{
    private:
        Deck _deck;
        House _house;
        vector<Player> _players;
    public:
        Game();
        void play();
};
