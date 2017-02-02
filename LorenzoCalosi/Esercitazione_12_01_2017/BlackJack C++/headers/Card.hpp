class Card
{
    private:
        Rank _rank;
        Suit _suit;
        bool _isFaceUp;

    public:
        Card();
        ~Card();
        Card(Rank r, Suit s);
        int getValue();
        void flip();
        void printCard();

        enum Rank {
            A = 1,
            TWO = 2,
            THREE = 3,
            FOUR = 4,
            FIVE = 5,
            SIX = 6,
            SEVEN = 7,
            EIGHT = 8,
            NINE = 9,
            TEN = 10,
            J = 10,
            Q = 10,
            K = 10
        };

        enum Suit {
            S = 1,
            C = 2,
            D = 3,
            H = 4
        };
};
