#include "Game.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
using namespace std;

Game::Game(int shoe_size)
{
    shoe_size = shoe_size;
    for(int i = 0; i < 52 * shoe_size; i++)
    {
        Shoe.push_back(1 + i % 13);
    }
    cout << "Starting the game \n";
    cout << "Shoe size: " << 1. * Shoe.size() / 52 << " decks \n";
    cout << "Card check: " << *(Shoe.begin() + 28) << "\n";

    auto rand = default_random_engine {};
    shuffle(begin(Shoe), end(Shoe), rand);

    cout << "Card check: " << *(Shoe.begin() + 28) << "\n";//ctor
}

Game::deal(int cards_to_deal)
{
    while (cards_to_deal >= 0)
    {
        if (cards_to_deal == 0)
        return 0;
        if (!(cards_to_deal % 2))
        {
            Punto.push_back(Shoe[Shoe.size() - 1]);
            Shoe.pop_back();
            cards_to_deal--;
        };
        if (cards_to_deal % 2)
        {
            Banco.push_back(Shoe[Shoe.size() - 1]);
            Shoe.pop_back();
            cards_to_deal--;
        };

    };


}

Game::result()
{
    cout << "Banco: ";
    while (!Banco.empty())
    {

        Banco.empty() ? cout << "    " : cout << Banco.back() << " ";
        Shoe.insert(Shoe.begin(), {Banco.back()});
        Banco.pop_back();
    }

    cout << "Punto: ";
    while (!Punto.empty())
    {
        Punto.empty() ? cout << "    " : cout << Punto.back() << " ";
        Shoe.insert(Shoe.begin(), {Punto.back()});
        Punto.pop_back();

    };
    reshuffle();
    cout << "\nShoe size: " << Shoe.size();

}

Game::reshuffle()
{
    auto rand = default_random_engine {};
    shuffle(begin(Shoe), end(Shoe), rand);
    cout << "\nCard check: " << *(Shoe.begin() + 28) << "\n";

}

Game::finish_dealing()
{
    return 0;
}

Game::deal(char deal_to)
{
    return 0;
}

Game::dealTern(int cards_to_deal)
{
    int test1 = cards_to_deal;
    int test2 = cards_to_deal % 2;
    char deal_to;

    !test1 ? finish_dealing()
        : test2 ? deal_to = 'b' : deal_to = 'p';
    deal(deal_to);


}

Game::~Game()
{
    //dtor
}
