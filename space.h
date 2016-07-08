// this is a space class. 
// this represents a single space on the playing board
// and can contain a tile
// The space can also have a bonus flag indicating that any 
// tile put here will give the word bonus points

#include<iostream>
#include "tile.h"

#pragma once

using namespace std;

class Space
{
    public:
        //default constructor
        Space();
        //copy constructor
        Space(const Space & space);
        // destructor
        virtual ~Space();

        virtual void display();
        virtual Space *&get_previous();
        virtual Space *&get_next();

    protected:
        Space *previous;
        Space *next;
};
