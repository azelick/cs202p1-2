//implementation for hand.h

#import "hand.h"

Hand::Hand(): hand(NULL), head(NULL)
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
    copy_list(head, ref_hand.head);
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
    delete_all(head);
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

void Hand::set_dict_match_list(Dict_Word * new_head)
{
    head = new_head;
}

void Hand::copy_list(Dict_Word *& head, Dict_Word * src_head)
{
    if(!src_head)
    {
        head = NULL;
        return;
    }
    head = new Dict_Word();
    head->word = new char[strlen(src_head->word) + 1];
    strcpy(head->word, src_head->word);
    copy_list(head->next, src_head->next);
}

void Hand::delete_all(Dict_Word *&current)
{
   if(!current)
       return;
   delete_all(current->next);
   delete current;
   return;
}

void Hand::display_possibles_list()
{
    Dict_Word *current = head;
    while(current != NULL)
    {
        cout << current->word << endl;
        current = current->next;
    }
}
