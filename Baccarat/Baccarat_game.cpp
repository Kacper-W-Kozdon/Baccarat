#include <iostream>
#include <vector>
#include "Game.h"
using namespace std;

void gameplay_loop(Game game1)
{
    game1.burn();
    game1.deal(game1.cards_to_deal);
    game1.result();
}

int main() {
    Game game1(8);
    char reshuffle;
    gameplay_loop(game1);
    cout << "\n[R]eshuffle, [Q]uit\n";

    while (reshuffle != 'Q')
    {
        cin >> reshuffle;

        if (reshuffle == 'R')
            gameplay_loop(game1);
        if (reshuffle == 'Q')
            break;
        cout << "\n[R]eshuffle, [Q]uit\n";
    };


    return 0;

}
