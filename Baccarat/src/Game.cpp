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

Game::Deal(int cards_to_deal)
{
    if (cards_to_deal == 0)
        return 0;
    if (!(cards_to_deal % 2))
    {
        Punto.push_back(Shoe.end());
        Shoe.pop_back();
        return 1;
    };
    if ((cards_to_deal % 2))
    {
        Banco.push_back(Shoe.end());
        Shoe.pop_back();
        return 1;
    };

}

Game::~Game()
{
    //dtor
}
