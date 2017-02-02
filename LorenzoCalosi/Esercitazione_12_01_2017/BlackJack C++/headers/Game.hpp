#include "Deck.hpp"
#include "House.hpp"
#include "Player.hpp"
#include <vector>

class Game
{
    private:
        Deck _deck;
        House _house;
        vector<Player> _players;
    public:
        Game();
        Game(vector<string> playerNames);
        ~Game();
        void playRound();
};
