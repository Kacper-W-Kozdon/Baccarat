#include "Game.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include<chrono>
using namespace std;

Game::Game(int shoe_size)
{
    shoe_size = shoe_size;
    cards_to_deal = 0;
    BancoScore = 0;
    PuntoScore = 0;
    for(int i = 0; i < 52 * shoe_size; i++)
    {
        Shoe.push_back(1 + i % 13);
    }

    cout << "Starting the game \n";
    cout << "Shoe size: " << 1. * Shoe.size() / 52 << " decks \n";
    unsigned int seed = chrono::steady_clock::now().time_since_epoch().count();
    auto rand = default_random_engine {};
    rand.seed(seed);
    shuffle(begin(Shoe), end(Shoe), rand);

    cout << "Card check: " << *(Shoe.begin() + 28) << "\n";//ctor
}

Game::Punto_rules()
{
    if (PuntoScore <= 5)
    {
        Punto.push_back(Shoe.back());
        PuntoScore += Punto.back();
        PuntoScore = PuntoScore % 10;
        Shoe.pop_back();
        Banco_rules("");
    }
    else
    {
        Banco_rules("y");
    }


}

Game::Banco_rules(const char* s = "n")
{
    if (Punto.size() <= 2)
        if (BancoScore <= 5)
            {
                Banco.push_back(Shoe.back());
                PuntoScore += Banco.back();
                Shoe.pop_back();
            };



    if (Punto.size() > 2)
            switch(BancoScore)
            {
                case (0 || 1 || 2):
                    Banco.push_back(Shoe.back());
                    PuntoScore += Banco.back();
                    Shoe.pop_back();
                    break;
                case (3):
                    if (Punto.back() % 10 != 8)
                    {
                        Banco.push_back(Shoe.back());
                        PuntoScore += Banco.back();
                        Shoe.pop_back();
                    };
                    break;
                case (4):
                    if (Punto.back() % 10 == 2 || Punto.back() % 10 == 3 || Punto.back() % 10 == 4 || Punto.back() % 10 == 5 || Punto.back() % 10 == 6 || Punto.back() % 10 == 7)
                    {
                        Banco.push_back(Shoe.back());
                        PuntoScore += Banco.back();
                        Shoe.pop_back();
                    };
                    break;
                case (5):
                    if (Punto.back() % 10 == 4 || Punto.back() % 10 == 5 || Punto.back() % 10 == 6 || Punto.back() % 10 == 7)
                    {
                        Banco.push_back(Shoe.back());
                        PuntoScore += Banco.back();
                        Shoe.pop_back();
                    };
                    break;
                case (6):
                    if (Punto.back() % 10 == 6 || Punto.back() % 10 == 7)
                    {
                        Banco.push_back(Shoe.back());
                        PuntoScore += Banco.back();
                        Shoe.pop_back();
                    };
                    break;
                case (7):
                    break;
            }

            BancoScore = BancoScore % 10;
}




Game::rules()
{
    for (int i = 0; i < max(Punto.size(), Banco.size()); i++)
    {
        Banco[i] ? BancoScore += Banco[i] : BancoScore += 0;
        Punto[i] ? PuntoScore += Punto[i] : PuntoScore += 0;
    };

    PuntoScore = PuntoScore % 10;
    BancoScore = BancoScore % 10;

    switch(PuntoScore || BancoScore)
    {
        case (8):
            break;

        case (9):
            break;

        default:
            Punto_rules();
    };
}

Game::deal(int cards_to_deal)
{
    cout << "\nDealing\n";
    while (cards_to_deal >= 0)
    {
        if (cards_to_deal == 0)
            break;

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

Game::burn()
{
    Burnt.push_back(Shoe[Shoe.size() - 1]);
    cards_to_deal = Burnt.back() <= 10 ? Burnt.back() : 10;
    Shoe.pop_back();

    while (cards_to_deal > 0)
    {
        Burnt.push_back(Shoe[Shoe.size() - 1]);
        Shoe.pop_back();
        cards_to_deal--;
    };

    cout << "\nBurnt: " << Burnt.back() << "\n";

    cards_to_deal = 4;
}

Game& Game::result()
{
    rules();

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

    &(*this).reshuffle();
    cards_to_deal = 0;

    cout << "\nPunto score: " << PuntoScore << "    Banco score: " << BancoScore;
    cout << "\nShoe size: " << Shoe.size() << ", " << (Shoe.size() / 52) << " decks\n";
    BancoScore = 0;
    PuntoScore = 0;
    return *this;
}

Game& Game::reshuffle()
{
    unsigned int seed = chrono::steady_clock::now().time_since_epoch().count();
    auto rand = default_random_engine {};
    rand.seed(seed);
    while (!Burnt.empty())
    {
        Shoe.insert(Shoe.begin(), {Burnt.back()});
        Burnt.pop_back();
    };

    shuffle(begin(Shoe), end(Shoe), rand);
    this->Shoe = Shoe;
    return *this;
}

Game::finish_dealing()
{
    return 0;
}

Game::deal(char)
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
