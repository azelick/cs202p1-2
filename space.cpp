// Implementation for space.h

#include "space.h"

//default constructor
Space::Space()
{
    tile = NULL;
    is_bonus = false;
}

Space::Space(Tile & ref_tile, bool ref_is_bonus)
{
    *tile = ref_tile;
    is_bonus = ref_is_bonus;

}

//copy constructor
Space::Space(const Space & space)
{
    is_bonus = space.is_bonus;
    tile = new Tile();
    space.tile->copy_tile(tile);
}

//Destructor
Space::~Space()
{
    delete tile;
}

void Space::set_tile_in_space(Tile & ref_tile)
{
    *tile = ref_tile;
}

void Space::display_space_contents()
{
    if(tile != NULL)
        tile->display();

    if(is_bonus)
        cout << "This is a bonus tile." << endl;
}
