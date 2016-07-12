// Implementation for space.h

#include "space.h"

//default constructor
Space::Space(): previous(NULL), next(NULL)
{
    
}

//copy constructor
Space::Space(const Space & space)
{
    previous = space.previous;
    next = space.next;
}

//Destructor
Space::~Space()
{
    //TODO This might seg fault.
    if (previous)
    {
        delete previous;
        previous = NULL;
        //delete previous;
    }
    if (next)
    {
        delete next;
        next = NULL;
    }
}

Space *&Space::get_previous()
{
    return previous;
}

Space *&Space::get_next()
{
    return next;
}
