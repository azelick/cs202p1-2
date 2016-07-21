//Implementation for TileBah.h
//Contains the pieces allowed for each game

#import "tile_bag.h"

TileBag::TileBag(): tiles(NULL), tiles_given_out(NULL), multiplier(1)
{

}

TileBag::TileBag(int requested_size)
{
    multiplier = generate_size(requested_size);

    tiles_in_bag = (multiplier*unit_size);

    //Tiles kept in the bag
    tiles = new Tile*[tiles_in_bag + 1];
    for (int i = 0; i < tiles_in_bag; ++i)
        tiles[i] = NULL;
    tiles[tiles_in_bag] = NULL;

    //Tiles given out
    tiles_given_out = new Tile*[tiles_in_bag + 1];
    for (int i = 0; i <= tiles_in_bag; ++i)
        tiles_given_out[i] = NULL;

    populate();
    return;
}

TileBag::TileBag(const TileBag &tileBag)
{
   multiplier = tileBag.multiplier;
   tiles_in_bag = multiplier*unit_size;
   tiles = new Tile*[tiles_in_bag];
   for( int i = 0; i < tiles_in_bag; ++i)
   {
       tiles[i] = new Tile(*(tileBag.tiles[i]));
   }
   return;
}

TileBag::~TileBag()
{
    if(tiles)
    {
        for(int i = 0; i < tiles_in_bag; ++i)
            delete tiles[i];
    }
    delete [] tiles;
    int i = 0;
    if(tiles_given_out)
    {
        while(tiles_given_out[i] != NULL)
        {
            delete tiles_given_out[i];
            ++i;
        }
    }
    delete [] tiles_given_out;
    
    return;
}

void TileBag::populate()
{
        char consonants[21] = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'R', 'V', 'W', 'X', 'Y', 'Z'};
        char vowels[5] = {'A', 'E', 'I', 'O', 'U'};

        int i = 0;
        int t = 0;
       while (t < multiplier)
       {
           //add consonants, and each consonant is worth 2 points
           for (int v = 0; v < 21; ++v)
           {
               tiles[i] = new Tile(consonants[v], 2);
               ++i;
           }
           //add vowels, each is worth 1 point
           for (int v = 0; v < 5; ++v)
           {
                tiles[i] = new Tile(vowels[v], 1);
                ++i;
           }
           for (int v = 0; v < 5; ++v)
           {
                tiles[i] = new Tile(vowels[v], 1);
                ++i;
           }
           for (int v = 0; v < 5; ++v)
           {
                tiles[i] = new Tile(vowels[v], 1);
                ++i;
           }
           for (int v = 0; v < 5; ++v)
           {
                tiles[i] = new Tile(vowels[v], 1);
                ++i;
           }
           ++t;
       }
       shuffle_tiles();
       return;
}

Tile * TileBag::get_random_tile()
{
    int i = 0;
    while(tiles[i] == NULL)
        ++i;
    Tile * temp = tiles[i];
    tiles[i] = NULL;
    return temp;
}

void TileBag::return_to_unused(Tile *tile)
{
     int i = 0;
    while(tiles[i] != NULL)
        ++i;
    tiles[i] = tile;
    return;


}

void TileBag::put_tile_back(Tile *tile)
{
    int i = 0;
    while(tiles_given_out[i] != NULL && tiles_given_out[i] != tile)
        ++i;
    return_to_unused(tile);
    tiles[i] = NULL;
    return;
}

int TileBag::generate_size(int requested_size)
{   
    // we want one more unit than calculated.
    int to_return = (requested_size/unit_size) + 1;
    return to_return;
}

void TileBag::shuffle_tiles()
{
    if(!tiles)
        return;
    int mult = tiles_in_bag*3;
    for(int i = 0; i < mult; ++i)
    {
        int index1 = rand()%tiles_in_bag;
        int index2 = rand()%tiles_in_bag;
        Tile *temp = tiles[index1];
        tiles[index1] = tiles[index2];
        tiles[index2] = temp;
    }

   return;
}
