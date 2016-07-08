//Implementation for TileBah.h
//Contains the pieces allowed for each game

#import "TileBag.h"

TileBag::TileBag(): tiles(NULL), size(0)
{

}

TileBag::TileBag(int requested_size)
{
    tiles = new Tile[requested_size];
    populate();
}

void TileBag::populate()
{

    //TODO Find a way to fill this with a random number of tiles. We should 
    // predetermine how many of each. Then add that may to the array. Then shuffle.
}

Tile * TileBag::get_random_tile()
{
    //TODO look up ways to shuffle an array
    //Then we can return the next piece in an array.
}

