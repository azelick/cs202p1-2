#pragma once

struct Dict_Word
{
    Dict_Word(): word(NULL), next(NULL)
    {
    }
    char * word;
    Dict_Word * next;
};

struct Coordinate
{
    int x;
    int y;
    // for direction, 1 is horizontal, 0 is down
    int direction;
};
