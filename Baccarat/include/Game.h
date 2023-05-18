#ifndef GAME_H
#define GAME_H
#include <vector>
using namespace std;


class Game
{
    public:

        int shoe_size;
        int cards_to_deal;

        Game(int shoe_size);
        deal(int cards_to_deal);
        dealTern(int cards_to_deal);

        virtual ~Game();

    protected:

    private:
        deal(char deal_to);
        finish_dealing();
        vector<int> Shoe;
        vector<int> Punto;
        vector<int> Banco;
};

#endif // GAME_H
