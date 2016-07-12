//A bag to manage the number of tiles
// when it is created with requested size it will 
// allocate an array then populate it with letters of the alphabet
//
// this class has an array of tiles


#include <iostream>
#include "tile.h"
#include <math.h>

using namespace std;

class TileBag
{
    public:
        //default constructor
        TileBag();
        //arg constructor
        TileBag(int requested_size);
        //copy constructor
        TileBag(const TileBag &tileBag);
        //destructor
        ~TileBag();
        
         //provide the caller with a random tile from the 'bag'
        Tile * get_random_tile();
        //put a tile back in the array
        void put_tile_back(Tile &tile); 

    protected:
        Tile **tiles;
        int multiplier;
        int tiles_in_bag;
        //one unit is 20 consonants, 4 times the 5 vowels
        // and one y
        static const int unit_size = 41;

        //shuffle the order of the tiles
        void shuffle_tiles();
        //fill the bag with tiles
        void populate();
        //calculate how many tiles we need
        int generate_size(int requested_size);
};
