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
    tile = *ref_tile;
    is_bonus = ref_is_bonus;

}

//copy constructor
Space::Space(const Space & space)
{


}

//Destructor
Space::~Space();
{

}

void Space::set_space_with_tile(Tile & ref_tile)
{


}

void Space::display_space_contents()
{


}
