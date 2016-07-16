//implementation for hand.h

#import "hand.h"

Hand::Hand(): hand(NULL)
{

}

Hand::Hand(Board &board)
{
    hand = new Tile*[7+1];
    draw_new_hand(board);
    return;
}

Hand::Hand(const Hand & ref_hand)
{
    hand = new Tile *[7+1];
    for (int i = 0; i < 7; ++i)
    {
        hand[i] = ref_hand.hand[i];
    }
    hand[8] = NULL;
    return;
}

Hand::~Hand()
{
    for(int i = 0; i < 7; ++i)
    {
        if (hand[i])
            delete hand[i];
    }
    delete hand;
    return;
}

void Hand::display()
{
    cout << endl;
    for(int i = 0; i < 7; ++i)
    {
        if(hand[i] != NULL)
        {
            hand[i]->display();
            cout << endl;
        }
    }
    cout << endl;
    return;
}

void Hand::draw_new_hand(Board &board)
{
    if(!hand)
    {
        hand = new Tile*[7+1];
        hand[8] = NULL;
    }
    for(int i = 0; i < 7; ++i)
    {
        hand[i] = get_tile_from_bag(board);
    }
    return;
}

void Hand::replace_tile(Board &board, char letter)
{

    int i = 0;
    while (hand[i]->get_letter() != letter) 
        ++i;
    put_tile_back(board, *hand[i]);
    hand[i] = NULL;
    hand[i] = get_tile_from_bag(board);
    return;
}

Tile * Hand::get_tile_from_bag(Board &board)
{
    return board.get_random_tile();
}

void Hand::put_tile_back(Board &board, Tile &tile)
{
    board.put_tile_back(tile);
    return;
}

void Hand::place_tile_on_board(Board &board, char letter, int x, int y)
{
    Tile * tile;
    int i = 0;
    while((hand[i] != NULL) && (hand[i]->get_letter() != letter))
        ++i;
    tile = hand[i];
    hand[i] = NULL;
    board.lay_tile_on_board(tile, x, y);
    return;
}
