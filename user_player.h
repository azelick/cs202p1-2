//TODO Comments

#import "hand.h"
#import "error.h"
#import <iostream>
#import <cctype>
#import <cstring>

using namespace std;

class User_Player: public Hand
{

    public:
        //default constructor
        User_Player();
        //copy constructor
        User_Player(const User_Player &user_player);
        //argument constructor
        User_Player(char * name, Board *board);
        ~User_Player(); 

        void query_dictionary(Board *board);
        char get_user_choice();
        void make_play(Board *board); 

    protected:

        //check if user's input is valid
        bool again(char response);
        void get_and_send_word_to_board();
        bool another_letter();
        void get_and_send_tiles_to_board(Board *board);
};
