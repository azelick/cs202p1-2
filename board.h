//This is the main board class for the scrabble program
//It should hold and create the board spaces and be able to
// do other actions related to the board.

#include<iostream>
#include "row_space.h"
#include "dictionary.h"
#include "TileBag.h"

using namespace std;

enum Direction { Vertical, Horizontal };

class Board
{
    public:
        //default constructor
        Board();
        // argument constructor
        Board(int size);
        //copy constructor
        Board(const Board & board);
        //destructor
        ~Board();
        void display();
        bool lay_tile_on_board(const Tile * tile, int x, int y, Direction dir);
        

    protected:
        Space * head;
        //Dictionary * dictionary;
        TileBag * bag;


        bool is_in_dictionary(const char * word);
        //recursive function to create the spaces
        void create_spaces(Space *&current, int current_index, const int size);
};
