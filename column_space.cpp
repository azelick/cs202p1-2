//


#include "column_space.h"

Column_Space::Column_Space(): head(NULL)
{

}

Column_Space::Column_Space(int length)
{
    if(length>0)
    {
        head = new Row_Space();
        head->get_previous() = NULL;
        create_row_spaces(head, --length);
    }
    else
    {
        head = NULL;
    }
}

Column_Space::Column_Space(const Column_Space &column_space)
{
    previous = NULL;
    next = NULL;
    head = column_space.head;
   copy_column_space(head, column_space.head);
}

Column_Space::~Column_Space()
{
    delete head;
}

void Column_Space::display()
{
    Row_Space *current = head;
    while(current != NULL)
    {
        current->display(); 
        current = current->get_next();
    }
    current = NULL;
}

void Column_Space::create_row_spaces(Row_Space *&head, int length_remaining)
{
    if(head == NULL)
        return;
    if(length_remaining <= 0)
    {
        head->get_next() = NULL;
        return;
    }
    head->get_next() = new Row_Space();
    head->get_next()->get_previous() = head;
    create_row_spaces(head->get_next(), --length_remaining);
}

void Column_Space::copy_column_space(Row_Space *&space, Row_Space* source_space)
{
    
    if(!source_space)
       return;

    space->get_next() = new Row_Space(*(source_space->get_next()));
    copy_column_space(space->get_next(), source_space->get_next());
    return;
}

Column_Space *& Column_Space::get_previous()
{
    return previous;
}

Column_Space *& Column_Space::get_next()
{
    return next;
}

