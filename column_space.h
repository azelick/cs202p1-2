//This class contains the column linked list of spaces
// 
// It is a 'node' of my doubly linked list of doubly linked lists
//
// each Column space contains it's next and previous, along with a pointer 
// to a row space

#include "space.h"
#include "row_space.h"

#pragma once

using namespace std;

class Column_Space: public Space
{
    public:
        //default constructor
        Column_Space();
        //arg constructor
        Column_Space(int length);
        //copy constructor
        Column_Space(const Column_Space & column_space);
        //destructor
        ~Column_Space();
        
        void display();

        //returns the Column_Space at a given index
        Column_Space * col_space_at_index(int index);
        //accessor functions that access protected data
        //Column_Space *& get_previous();
        //Column_Space *& get_next();
        Row_Space *& get_head();
        //recursive function called by col_space_at_index()
        void traverse(Column_Space *& dest_col, Column_Space * current, int current_index, int index);
        //recursie copy function used in the copy constructor
        void copy_column_space(Row_Space *&head, Row_Space * source_head);

    protected:
        Row_Space *head;
        //Column_Space *previous;
        //Column_Space *next;

        // used in the constructor to create the rows.
        void create_row_spaces(Row_Space *&head, int length_remaining);
};
