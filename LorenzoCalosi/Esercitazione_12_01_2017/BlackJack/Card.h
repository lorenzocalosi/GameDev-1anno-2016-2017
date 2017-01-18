enum Rank {A = 1, J = 10, Q = 10, K = 10};
enum Suit {S = 1, C = 2, D = 3, H = 4};

class Card
{
    private:
        Rank _rank;
        Suit _suit;
        bool _isFaceUp;

    public:
        Card();
        Card(Rank r, Suit s);
        int getValue();
        void flip();
        void printCard();
};
