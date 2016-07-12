// implementation for board.h


#include "board.h"

Board::Board(): head(NULL), bag(NULL), size(0)
{

}

Board::Board(int board_size): size(board_size)
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
    bag = new TileBag(board_size);
    return;
}

Board::Board(const Board & board)
{
    //TODO This needs to be implemented
    size = board.size;
    //head = new Column_Space(board->head);
    copy_board_columns(head, board.head);
    bag = new TileBag(*board.bag);
    return;
}

Board::~Board()
{
    if(head)
        delete head;
    //if(dictionary)
    //    delete dictionary;
    if(bag)
        delete bag;
    return;
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
    return;
}

bool Board::lay_tile_on_board(Tile * tile, int x, int y)
{
    Row_Space * space =  traverse_to_space(x, y);
    if (space->is_occupied())
        return false;
    space->set_tile_in_space(tile);
    return true;
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
    return;
}

Row_Space * Board::traverse_to_space(int x_coord, int y_coord)
{

    Column_Space * col = head->col_space_at_index(y_coord);
    //returning final_destination by reference
    return col->get_head()->row_space_at_index(x_coord);
}

void Board::set_premium()
{
   Row_Space * row;
   for(int i = 0; i < size; i++)
   {
        row = traverse_to_space(i, i);
        row->set_as_bonus();
        row = traverse_to_space(i, (size - 1 - i));
        row->set_as_bonus();
   }
   return;
}

Tile * Board::get_random_tile()
{
    return bag->get_random_tile();
}

void Board::put_tile_back(Tile &tile)
{
    bag->put_tile_back(tile);
    return;
}

void Board::copy_board_columns(Column_Space *&current, Column_Space * src_head)
{
    if (!src_head)
        return;
    if (!current)
    {
        current = new Column_Space(*src_head);
        current->get_previous() = NULL;
    }
    if (src_head->get_next())
    {
        current->get_next()= new Column_Space(*(src_head->get_next()));
        current->get_next()->get_previous()= current;
    }
    current->copy_column_space(current->get_head(), src_head->get_head());
    return;
}
