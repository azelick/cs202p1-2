//Implementation for TileBah.h
//Contains the pieces allowed for each game

#import "tile_bag.h"

TileBag::TileBag(): tiles(NULL), multiplier(1)
{

}

TileBag::TileBag(int requested_size)
{
    multiplier = generate_size(requested_size);
    cout << multiplier << endl;
    cout << unit_size << endl;
    cout << (multiplier*unit_size);
    int tiles_in_bag = (multiplier*unit_size);
    tiles = new Tile*[tiles_in_bag];
    for (int i = 0; i < tiles_in_bag; i++)
        tiles[i] = NULL;
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
    // we want one more unit than what's even.
    int to_return = (requested_size/unit_size) + 1;
    return to_return;
}

void TileBag::shuffle_tiles()
{
    if(!tiles)
        return;
   random_shuffle(tiles[0], tiles[(unit_size*multiplier)-1]);
}
