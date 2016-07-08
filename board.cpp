// implementation for board.h


#include "board.h"

Board::Board(): head(NULL), bag(NULL)
{
   //TODO add dictionary to initialization list for proram2 
}

Board::Board(int board_size)
{
    //this sets head so we aren't setting it otherwise
    if(board_size > 0)
    {
        head = new Column_Space(board_size);
        head->get_previous() = NULL;
        create_spaces(head, (board_size - 1), board_size);
    }
    else
    {
        head = NULL;
    }
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
    Column_Space *current = head;
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

void Board::create_spaces(Column_Space *&current, int length_remaining, int max_size)
{
    if(current == NULL)
        return;
    if(length_remaining <= 0)
    {
        current->get_next() = NULL;
        return;
    }

    current->get_next() = new Column_Space(max_size);
    cout << "A column Space has been made" << endl;
    current->get_next()->get_previous() = current;
    create_spaces(current->get_next(), --length_remaining, max_size);
    
}
