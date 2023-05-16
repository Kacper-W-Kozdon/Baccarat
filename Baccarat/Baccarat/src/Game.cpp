#include "Game.h"
#include <iostream>
#include <vector>
using namespace std;
Game::Game(int x)
{
    shoe_size = x;
    for(int i = 0; i < 52 * shoe_size; i++)
    {
        Shoe.push_back(1 + i % 13);
    }
    cout << "Starting the game \n";
    cout << "Shoe size: " << 1. * Shoe.size() / 52 << " decks \n";
    cout << "Card check: " << *(Shoe.begin() + 28);//ctor
}

Game::~Game()
{
    //dtor
}
