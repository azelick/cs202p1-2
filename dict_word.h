#pragma once

struct Dict_Word
{
    Dict_Word(): word(NULL), next(NULL)
    {
    }
    char * word;
    Dict_Word * next;
};
