//Implementation for row spaces
//

#include "row_space.h"

Row_Space::Row_Space(): tile(NULL), is_bonus(false)
{

}

Row_Space::Row_Space(Tile & ref_tile, bool ref_is_bonus)
{
    *tile = ref_tile;
    is_bonus = ref_is_bonus;
}

Row_Space::Row_Space(const Row_Space &row_space): is_bonus(false)
{
    previous = row_space.previous;
    next = row_space.next;
    tile->copy_tile(row_space.tile);
}

Row_Space::~Row_Space()
{
    if (tile)
        delete tile;
    if (next)
        delete next;
}

void Row_Space::set_tile_in_space(Tile &ref_tile)
{
    *tile = ref_tile;
}


void Row_Space::display()
{
    if(tile != NULL)
        tile->display();

    if(is_bonus)
        cout << "This is a bonus tile." << endl;
    //TODO the below line is only for testing
    cout << "Here is a space" << endl;

}


Row_Space *& Row_Space::get_previous()
{
    return previous;
}

Row_Space *& Row_Space::get_next()
{
    return next;
}

