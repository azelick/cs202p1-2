//This is the main board class for the scrabble program
//It should hold and create the board spaces and be able to
// do other actions related to the board.

#include <iostream>
#include "column_space.h"
#include "dictionary.h"
#include "tile_bag.h"
#include "tile.h"

using namespace std;

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
        bool lay_tile_on_board(Tile * tile, int x, int y);
        void set_premium(); 
        Row_Space * traverse_to_space(int x_coord, int y_coord);
        Tile * get_random_tile();
        void put_tile_back(Tile &tile);

    protected:
        Column_Space * head;
        //Dictionary * dictionary;
        TileBag * bag;
        int size;

        bool is_in_dictionary(const char * word);
        //recursive function to create the spaces
        void create_spaces(Column_Space *&current, int length_remaining, int max_size);
        void copy_board_columns(Column_Space *&head, Column_Space * src_head);
};
