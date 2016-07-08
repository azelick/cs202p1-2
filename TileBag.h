//A bag to manage the number of tiles


#include<iostream>
#include "tile.h"

using namespace std;

class TileBag
{
    public:
        //default constructor
        TileBag();
        //arg constructor
        TileBag(int requested_size);
        

    protected:
        Tile *tiles;
        int size;

        //fill the bag with tiles
        void populate();
        //return a random tile from the 'bag'
        Tile * get_random_tile();
};
