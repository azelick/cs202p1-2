// contains tiles

#include <iostream>
#include "tile.h"
#include "board.h"

using namespace std;

class Hand
{
    public:
        //default constructor
        Hand();
        //arg constructor
        Hand(Board &board);
        //copy constructor
        Hand(const Hand & hand);
        //destructor
        ~Hand();

        void display();
        void draw_new_hand(Board &board);
        void replace_tile(Board &board, char letter);
        void place_tile_on_board(Board &board, char letter, int x, int y);

    protected:
        Tile **hand;

        Tile * get_tile_from_bag(Board &board);
        void put_tile_back(Board &board, Tile &tile);

};
