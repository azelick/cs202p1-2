//TODO Comments

#import "hand.h"
#import "error.h"
#import <iostream>
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
        User_Player(char * name, Board *&board);
        ~User_Player(); 

        bool query_dictionary(const Board *&board);
        char * get_user_input();
        void make_play(Board *&board); //TODO
        bool concede(); //TODO

    protected:

        //check if user's input is valid
        bool again(char * response);
};
