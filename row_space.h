//This class contains the column linked list of spaces
// It will contain the actual tiles
// these rows comprise the actual board's playing spaces. They can display themselves
// It also has a tile along with the previous and next pointers of the doubly linked list
// data structure
//
// The tile, is_bonus and previous/next data members should all be protected so they can't be 
// messed with.


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

        //set 'tile' with a Tile
        void set_tile_in_space(Tile *ref_tile);
        void display();

        // set is_bonus
        void set_as_bonus();
        //return true if there is a tile here already
        bool is_occupied();

        //return a pointer to the Row_Space that occupies the given index
        Row_Space * row_space_at_index(int index);
        //recursive function called by row_space_at_index
        void traverse(Row_Space *& dest_space, Row_Space * current, int current_index, int index);

        //wrapper functions to provide the previous and next pointers
        Row_Space *& get_previous();
        Row_Space *& get_next();

    protected:
        Tile *tile;
        bool is_bonus;

        Row_Space * previous;
        Row_Space * next;
};
