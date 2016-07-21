// 


#import "ai_player.h"

Ai_Player::Ai_Player(): Hand()
{

}

Ai_Player::Ai_Player(const Ai_Player &user_player): Hand(user_player)
{
}

Ai_Player::Ai_Player(const char * name, Board *&board): Hand(name, board)
{
}

Ai_Player::~Ai_Player()
{
}

void Ai_Player::find_plays_in_hand(Board *&board)
{
    //TODO don't have time to implement more that checking the first letter for AI
    char * temp = NULL;
    get_hand(temp);
    char first_letter = temp[0];
    cout << "1" << endl;
    set_dict_match_list(board->find_words_with_letter(first_letter));
    cout << "2" << endl;
    groom_for_playable_words();
    cout << "3" << endl;
    display_possibles_list();

    delete temp;
}

void Ai_Player::make_play(Board *&board)
{
    find_plays_in_hand(board);
       
    //head->word is just grabing the first playable word from the ai hand
    Coordinate space_to_play = board->find_playable_location(head->word);
    int word_size = strlen(head->word);
    //if direction is 1, we are playing horizontally
    int turn_score = 0;
    if(space_to_play.direction)
    {
        for(int i = 0; i < word_size; ++i)
        {
            place_tile_on_board(board, head->word[i], i + space_to_play.x, space_to_play.y);
            turn_score += replace_tile(board, head->word[i]);
        } 

    }
    else 
    {
        for(int i = 0; i < word_size; ++i)
        {
            place_tile_on_board(board, head->word[i], space_to_play.x, i + space_to_play.y);
            turn_score += replace_tile(board, head->word[i]);
            
        }
    } 
}

