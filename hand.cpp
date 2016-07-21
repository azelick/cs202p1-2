//implementation for hand.h

#import "hand.h"

Hand::Hand(): hand(NULL), score(0), player_name(NULL), head(NULL)
{

}

Hand::Hand(const char *new_name, Board *&board): score(0), head(NULL)
{
    hand = new Tile*[7+1];
    hand[7] = NULL;
    draw_new_hand(board);
    player_name = new char[(strlen(new_name) + 1)];
    strcpy(player_name, new_name);
    return;
}

Hand::Hand(const Hand & ref_hand)
{
    hand = new Tile *[7+1];
    for (int i = 0; i < 7; ++i)
    {
        hand[i] = ref_hand.hand[i];
    }
    hand[7] = NULL;
    copy_list(head, ref_hand.head);
    score = ref_hand.score;
    if(!(ref_hand.player_name == NULL))
    {
        player_name = new char[(strlen(ref_hand.player_name) + 1)];
        strcpy(player_name, ref_hand.player_name);
    }
   else 
   {
       player_name = NULL;
   }
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
    if(player_name)
        delete player_name;
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

void Hand::draw_new_hand(Board *&board)
{
    if(!hand)
    {
        hand = new Tile*[7+1];
        hand[7] = NULL;
    }
    for(int i = 0; i < 7; ++i)
    {
        hand[i] = get_tile_from_bag(board);
    }
    return;
}

int Hand::replace_tile(Board *&board, char letter)
{
    bool was_removed = false;
    int point_value = 0;
    for(int i = 0; i < 7 && was_removed == false; ++i)
    {
        if(hand[i] != NULL)
        {
            if(hand[i]->get_letter() == letter)
            {
                point_value += hand[i]->get_point_value();
                delete hand[i];
                hand[i] = NULL;
                hand[i] = board->get_random_tile();
                was_removed = true;
            }
        }
    }
    return point_value;
}

Tile * Hand::get_tile_from_bag(Board *&board)
{
    return board->get_random_tile();
}

void Hand::put_tile_back(Board *&board, Tile &tile)
{
    board->put_tile_back(tile);
    return;
}

void Hand::place_tile_on_board(Board *&board, char letter, int x, int y)
{
    Tile * tile;
    int i = 0;
    while((hand[i] != NULL) && (hand[i]->get_letter() != letter))
        ++i;
    tile = hand[i];
    board->lay_tile_on_board(tile, x, y);
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

void Hand::groom_for_playable_words()
{
    remove_non_matches(head, head);
}

void Hand::remove_non_matches(Dict_Word *&previous, Dict_Word *&current)
{
    if(!current)
        return;

    if(!playable_from_hand(current->word))
    {
        Dict_Word *temp = current;
        //case for only one in list
        if(previous == current)
        {
            current = temp->next;
        }
        else
        {
            current = previous;
            current->next = temp->next;
            temp->next = NULL;
        }
       if(temp->word)
           delete temp->word;
       delete temp;
       remove_non_matches(current, current);
    }
    else
        remove_non_matches(current, current->next);
}

bool Hand::playable_from_hand(char * word)
{
    //do a contains check for each letter in the word
    //We'll have an issue if the word requires double letters but... oh well

    if(!word)
        return false;
    bool does_match = true;
    int size = strlen(word);
    for(int i = 0; i < size; ++i)
    {
        char * temp_hand = NULL;
        get_hand(temp_hand);
        if(!strchr(temp_hand, word[i]))
            does_match = false;
        delete temp_hand;
    }
    return does_match;
}

void Hand::get_hand(char *&return_hand)
{
    //we should be passed a null pointer
    if(return_hand)
        return;
    return_hand = new char[8];
    for(int i = 0; i < 7; ++i)
        return_hand[i] = hand[i]->get_letter();
    return_hand[7] = '\0';
}

int Hand::get_score()
{
    return score;
}

bool Hand::contains_letter(const char letter)
{
    bool contains = false;
    for(int i = 0; i < 7; ++i)
    {
        if(hand[i]->get_letter() == letter)
            contains = true;
    }
    return contains;
}

