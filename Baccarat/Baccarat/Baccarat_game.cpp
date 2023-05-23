#include <iostream>
#include <vector>
#include "Game.h"
using namespace std;

void gameplay_loop()
{
    Game game1(8);
    game1.burn();
    game1.deal(game1.cards_to_deal);
    game1.result();
}

int main() {

    gameplay_loop();

    return 0;

}
