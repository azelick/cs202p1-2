//Implementation for TileBah.h
//Contains the pieces allowed for each game

#import "tile_bag.h"

TileBag::TileBag(): tiles(NULL), multiplier(1)
{

}

TileBag::TileBag(int requested_size)
{
    multiplier = generate_size(requested_size);

    tiles_in_bag = (multiplier*unit_size);
    cout << tiles_in_bag << endl;

    tiles = new Tile*[tiles_in_bag];
    cout << sizeof(tiles) << endl;
    for (int i = 0; i < tiles_in_bag; i++)
        tiles[i] = NULL;
    populate();
    return;
}

TileBag::TileBag(const TileBag &tileBag)
{
   multiplier = tileBag.multiplier;
   tiles_in_bag = multiplier*unit_size;
   tiles = new Tile*[tiles_in_bag];
   for( int i = 0; i < tiles_in_bag; i++)
   {
       tiles[i] = new Tile(*(tileBag.tiles[i]));
   }
   return;
}

TileBag::~TileBag()
{
    if(tiles)
    {
        for(int i = 0; i < tiles_in_bag; i++)
            delete tiles[i];
    }
    delete tiles;
    return;
}

void TileBag::populate()
{
        char consonants[21] = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z'};
        char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

        int i = 0;
        int t = 0;
       while (t < multiplier)
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
           //TODO shuffle isn't working yet, but wasn't explicitly a requirement of program 1
           //shuffle_tiles();
       }
    
       return;
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
   random_shuffle(tiles[0], tiles[(unit_size*multiplier)-1 ]);
   return;
}
