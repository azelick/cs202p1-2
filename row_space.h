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

        void set_tile_in_space(Tile *ref_tile);
        void display();
        //TODO Do I want to have an is_bonus() function?
        //bool is_bonus();

        void set_as_bonus();
        //return true if there is a tile here already
        bool is_occupied();

        Row_Space * row_space_at_index(int index);

        Row_Space *& get_previous();
        Row_Space *& get_next();
        void traverse(Row_Space *& dest_space, Row_Space * current, int current_index, int index);

    protected:
        Tile *tile;
        bool is_bonus;

        Row_Space * previous;
        Row_Space * next;

};
