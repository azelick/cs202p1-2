//


#include "column_space.h"

Column_Space::Column_Space(): Space(), head(NULL)
{

}

Column_Space::Column_Space(int length): Space()
{
    if(length>0)
    {
        head = new Row_Space();
        head->get_previous() = NULL;
        create_spaces(head, length);
    }
    head = NULL;
}

Column_Space::Column_Space(const Column_Space &column_space)
{
   copy_column_space(head, column_space.head);
}

Column_Space::~Column_Space()
{
    delete head;
}

void Column_Space::display()
{
    //This is for vitual purposes
    //Class doesn't actually have anything to display
}

void Column_Space::create_spaces(Row_Space *&head, int length_remaining)
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
    create_spaces((head->get_next()), length_remaining--);
}

void Column_Space::copy_column_space(Row_Space *&space, Row_Space* source_space)
{
    if(source_space)
        space->head = new Row_Space(source_space->head);
    copy_column_space(space->get_next(), source_space->get_next());
    return;
}
