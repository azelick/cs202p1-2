//This class contains the column linked list of spaces
// It will contain the actual tiles


#include "tile.h"
#pragma once

using namespace std;

class Row_Space
{
    public:
        //default constructor
        Row_Space();
        Row_Space(Tile & ref_tile, bool ref_is_bonus);
        //copy constructor
        Row_Space(const Row_Space & space);
        // destructor
        ~Row_Space();

        void set_tile_in_space(Tile &ref_tile);
        void display();
        //TODO Do I want to have an is_bonus() function?
        //bool is_bonus();

        Row_Space *&get_previous();
        Row_Space *&get_next();

    protected:
        Tile *tile;
        bool is_bonus;

        Row_Space * previous;
        Row_Space * next;

};
