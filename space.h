// this is a space class. 
// this represents a single space on the playing board
// and can contain a tile
// The space can also have a bonus flag indicating that any 
// tile put here will give the word bonus points

#include<iostream>
#include "tile.h"
using namespace std;

class Space
{
    public:
        //default constructor
        Space();
        Space(Tile & ref_tile, bool ref_is_bonus);
        //copy constructor
        Space(const Space & space);
        // destructor
        ~Space();
        void set_space_with_tile(Tile & ref_tile);
        void display_space_contents();
        //TODO Do I want to have an is_bonus() function?
        //bool is_bonus();

    protected:
        Tile * tile;
        bool is_bonus;

};
