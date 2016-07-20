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

void Ai_Player::display()
{
    Hand::display();
    cout << "Score: " << score << endl;
}

bool Ai_Player::is_play_in_hand(Board *&board)
{
    //TODO don't have time to implement more that checking the first letter for AI
    char first_letter = (get_hand())[0];
    set_dict_match_list(board->find_words_with_letter(first_letter));
    groom_for_playable_words();
    //TODO Take this out for final version
    cout << " plays AI could make" << endl;
    display_possibles_list();

}

void Ai_Player::make_play(Board *&board)
{
    is_play_in_hand(board);
        


}

