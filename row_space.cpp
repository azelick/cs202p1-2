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
    return;
}

Row_Space::Row_Space(const Row_Space &row_space): is_bonus(false)
{
    previous = row_space.previous;
    next = row_space.next;
    tile = new Tile(row_space.tile->get_letter(), row_space.tile->get_point_value());
    return;
}

Row_Space::~Row_Space()
{
    if (tile)
        delete tile;
    if (next)
        delete next;
    return;
}

void Row_Space::set_tile_in_space(Tile *ref_tile)
{
    tile = ref_tile;
    return;
}

void Row_Space::display()
{
    cout << "| ";
    if(tile != NULL)
        tile->display();
    else
        cout << "  -  ";

    if(is_bonus)
        cout << " - *";
    else
        cout << " -  ";
    cout << " | \t";
    return;
}

Row_Space *& Row_Space::get_previous()
{
    return previous;
}

Row_Space *& Row_Space::get_next()
{
    return next;
}

Row_Space * Row_Space::row_space_at_index(int index)
{
    Row_Space * row;
    traverse(row, this, 0, index);
    return row;
}

void Row_Space::traverse(Row_Space *& dest_space, Row_Space * current, int current_index, int index)
{
   if (!current) 
       return;

   if (current_index == index)
       dest_space = current;

   traverse(dest_space, current->next, ++current_index, index);
    return;
}

void Row_Space::set_as_bonus()
{
    is_bonus = true;
    return;
}

bool Row_Space::is_occupied()
{
    if(tile != NULL)
        return true;
    return false;
}
