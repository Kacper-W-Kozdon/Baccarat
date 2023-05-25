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
        burn();
        deal(int cards_to_deal);
        dealTern(int cards_to_deal);
        result();

        virtual ~Game();

    protected:

    private:
        deal(char deal_to);
        finish_dealing();
        rules();
        Punto_rules();
        Banco_rules(const char* s);
        int PuntoScore;
        int BancoScore;
        vector<int> Shoe;
        vector<int> Punto;
        vector<int> Banco;
        vector<int> Burnt;
        reshuffle();
};

#endif // GAME_H
