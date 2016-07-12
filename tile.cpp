// Comments TODO

#include "tile.h"
using namespace std;


// Default constructor
Tile::Tile(): letter(0), point_value(0)
{
}
   
Tile::Tile(char new_letter, int new_point_value)
{
    letter = new_letter;
    point_value = new_point_value;
}
// no dynamic memory means we don't need a destructor to do anything
Tile::~Tile(){}

//Member Functions
void Tile::display() {
    cout << letter << " - ";
    cout << point_value;
}

// Super not sure if I should have setters and getters
// or if I should just have public data with the const keyword
void Tile::set_letter(char new_letter)
{
    letter = new_letter;
}

void Tile::set_point_value(int new_value)
{
    point_value = new_value;
}

//copy this tile into the provided tile 
void Tile::copy_tile(Tile * tile) const
{
    tile->letter = letter;
    tile->point_value = point_value;
}

char Tile::get_letter()
{
    return letter;
}

int Tile::get_point_value()
{
    return point_value;
}
