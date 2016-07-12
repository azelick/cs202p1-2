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
    return;
}

// no dynamic memory means we don't need a destructor to do anything
Tile::~Tile(){}

void Tile::display() {
    cout << letter << " - ";
    cout << point_value;
    return;
}

void Tile::set_letter(char new_letter)
{
    letter = new_letter;
    return;
}

void Tile::set_point_value(int new_value)
{
    point_value = new_value;
    return;
}

void Tile::copy_tile(Tile * tile) const
{
    tile->letter = letter;
    tile->point_value = point_value;
    return;
}

char Tile::get_letter()
{
    return letter;
}

int Tile::get_point_value()
{
    return point_value;
}
