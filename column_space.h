//This class contains the column linked list of spaces


#include "row_space.h"

#pragma once

using namespace std;

class Column_Space
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

        Column_Space * col_space_at_index(int index);
        Column_Space *& get_previous();
        Column_Space *& get_next();
        Row_Space *& get_head();
        void traverse(Column_Space *& dest_col, Column_Space * current, int current_index, int index);
        

    protected:
        Row_Space *head;
        Column_Space *previous;
        Column_Space *next;


        void create_row_spaces(Row_Space *&head, int length_remaining);
        void copy_column_space(Row_Space *&head, Row_Space * source_head);
};
