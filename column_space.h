//This class contains the column linked list of spaces


#include "row_space.h"

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

        

    protected:
        Row_Space *head;

        void create_spaces(Row_Space *&head, int length_remaining);
        void copy_column_space(Row_Space *&head, Row_Space * source_head);
};
