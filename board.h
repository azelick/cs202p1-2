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
        //place a tile on the board at the given coordinates
        bool lay_tile_on_board(Tile * tile, int x, int y);
        //put the premium squares on the board
        void set_premium(); 
        // get the row_space at the given coordinates
        Row_Space * traverse_to_space(int x_coord, int y_coord);
        //get a random tile from the tile bag
        Tile * get_random_tile();
        //put a tile back into the tile bag
        void put_tile_back(Tile &tile);
        bool check_word_is_valid(const char * word) const;
        void display_dictionary();
        Dict_Word * find_words_with_letter(const char letter);
        Coordinate find_playable_location(char * word);

    protected:
        Column_Space * head;
        Dictionary * dictionary;
        TileBag * bag;
        int size;

        //recursive function to create the spaces
        void create_spaces(Column_Space *&current, int length_remaining, int max_size);
        //recursive function called by the copy constructor
        void copy_board_columns(Column_Space *&head, Column_Space * src_head);
        bool is_contiguous_available(Coordinate &location, int length);
        Coordinate find_empty_space();

};
