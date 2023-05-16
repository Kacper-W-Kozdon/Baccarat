#ifndef GAME_H
#define GAME_H
#include <vector>
using namespace std;


class Game
{
    public:

        int shoe_size;

        Game(int shoe_size);

        virtual ~Game();

    protected:

    private:
        vector<int> Shoe;
};

#endif // GAME_H
