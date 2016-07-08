//Implementation for row spaces
//

#include "row_space.h"

Row_Space::Row_Space(): Space(), tile(NULL), is_bonus(false)
{

}

Row_Space::Row_Space(Tile & ref_tile, bool ref_is_bonus): Space()
{
    *tile = ref_tile;
    is_bonus = ref_is_bonus;
}

Row_Space::Row_Space(const Row_Space &space): Space(space), is_bonus(false)
{
    tile->copy_tile(space.tile);
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
