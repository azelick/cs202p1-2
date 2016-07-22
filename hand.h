// contains tiles
// This class has an collection of tiles
// that the player can play with. It can display itself and 
// knows how to get tiles from the board and return tiles to the board
// There are a couple wrapper functions that call the board's member functions
// 
// The hand 'uses' a board quite heavily, but does not have one.

#include <iostream>
#include "tile.h"
#include "board.h"
#include "structs.h"
#include <cstring>

using namespace std;

class Hand
{
    public:
        //default constructor
        Hand();
        //arg constructor
        Hand(const char *new_name, Board *board);
        //copy constructor
        Hand(const Hand & hand);
        //destructor
        ~Hand();

        void display();
        //draw a fresh 7 cards
        void draw_new_hand(Board *board);
        //replace the given tile with one from the bag
        int replace_tile(Board *board, char letter);
        //place the given tile on the board
        void place_tile_on_board(Board *board, char letter, int x, int y);
        void set_dict_match_list(Dict_Word * new_head);
        void display_possibles_list();
        void groom_for_playable_words();
        bool playable_from_hand(char * word);
        char * get_hand();
        //pure virtual function
        virtual void make_play(Board *board) =0;
        int get_score();
        bool contains_letter(const char letter);

    protected:
        Tile **tiles_in_hand;
        int score;
        char * player_name;
        char * hand;

        //list of possible word from player's hand
        Dict_Word *head;

        //wrapper function for board function
        Tile * get_tile_from_bag(Board *board);
        //wrapper function for board function
        void put_tile_back(Board *board, Tile *tile);
        void delete_all(Dict_Word *&current);
        void copy_list(Dict_Word *& head, Dict_Word * src_head);
        void remove_non_matches(Dict_Word *&previous, Dict_Word *&current);
};
