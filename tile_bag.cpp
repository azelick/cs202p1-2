//Implementation for TileBah.h
//Contains the pieces allowed for each game

#import "tile_bag.h"

TileBag::TileBag(): tiles(NULL), multiplier(1)
{

}

TileBag::TileBag(int requested_size)
{
    multiplier = generate_size(requested_size);
    tiles = new Tile*[(multiplier*unit_size)];
    populate();
}

void TileBag::populate()
{

    //TODO Find a way to fill this with a random number of tiles. We should 
    // predetermine how many of each. Then add that may to the array. Then shuffle.

    char consonants[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
    char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

    int i = 0;
    int t = 0;
   while (t <= multiplier)
   {
       //add consonants, and each consonant is worth 2 points
       for (int v = 0; v < 21; v++)
       {
           tiles[i] = new Tile(consonants[v], 2);
           i++;
       }
       //add vowels, each is worth 1 point
       for (int v = 0; v < 5; v++)
       {
            tiles[i] = new Tile(vowels[v], 1);
            i++;
       }
       for (int v = 0; v < 5; v++)
       {
            tiles[i] = new Tile(vowels[v], 1);
            i++;
       }
       for (int v = 0; v < 5; v++)
       {
            tiles[i] = new Tile(vowels[v], 1);
            i++;
       }
       for (int v = 0; v < 5; v++)
       {
            tiles[i] = new Tile(vowels[v], 1);
            i++;
       }
       t++;
       shuffle_tiles();
   }
}

Tile * TileBag::get_random_tile()
{
    int i = 0;
    while(tiles[i] == NULL)
        i++;
    Tile * temp = tiles[i];
    tiles[i] = NULL;
    return temp;
}

void TileBag::put_tile_back(Tile &tile)
{
    int i = 0;
    while(tiles[i] != NULL)
        i++;
    *tiles[i] = tile;
}

int TileBag::generate_size(int requested_size)
{
    // Take the consonants plus y
    // Then add 4 times as many vowels as consonants 
    // This will be a playing piece unit.
    // For each multiple of this number we will add to the array rounded to the nearest unit.

    int unit = 21+20;
    // round up
    return ceil(requested_size/unit);
   ;
}

void TileBag::shuffle_tiles()
{
    if(!tiles)
        return;
   random_shuffle(tiles[0], tiles[(41*multiplier)-1]);
}
