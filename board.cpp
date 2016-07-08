// implementation for board.h


#include "board.h"

Board::Board(): head(NULL), bag(NULL)
{
   //TODO add dictionary to initialization list for proram2 
}

Board::Board(int board_size)
{
    //this sets head so we aren't setting it otherwise
   create_spaces(head, 0, board_size);
   //dictionary = new(dictionary(arg));
   bag = new TileBag();
}

Board::Board(const Board & board)
{
    //TODO This needs to be implemented
}

Board::~Board()
{
    if(head)
        delete head;
    //if(dictionary)
    //    delete dictionary;
    if(bag)
        delete bag;
}

void Board::display()
{
    Space *current = head;
    while(current != NULL)
    {
        current->display(); 
        current = current->get_next();
    }
    current = NULL;
}

bool Board::lay_tile_on_board(const Tile * tile, int x, int y, Direction dir)
{

}

void Board::create_spaces(Space *&current, int current_index,  const int size)
{
    //if we've reached our maximum size, exit.
    if (current_index > size)
        return;
    if(!current)
        current = new Row_Space();
    
    current_index++;
    create_spaces(current->get_next(), current_index, size);
}
