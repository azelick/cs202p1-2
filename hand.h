// contains tiles
// This class has an collection of tiles
// that the player can play with. It can display itself and 
// knows how to get tiles from the board and return tiles to the board
// There are a couple wrapper functions that call the board's member functions
// 
// The hand 'uses' a board quite heavily, but does not have one.

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
        //draw a fresh 7 cards
        void draw_new_hand(Board &board);
        //replace the given tile with one from the bag
        void replace_tile(Board &board, char letter);
        //place the given tile on the board
        void place_tile_on_board(Board &board, char letter, int x, int y);

    protected:
        Tile **hand;

        //wrapper function for board function
        Tile * get_tile_from_bag(Board &board);
        //wrapper function for board function
        void put_tile_back(Board &board, Tile &tile);

};
