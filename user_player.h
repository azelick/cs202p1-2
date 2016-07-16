//TODO Comments

#import "hand.h"
#import "error.h"
#import <iostream>

using namespace std;

class User_Player: public Hand
{

    public:
        //default constructor
        User_Player();
        //copy constructor
        User_Player(const User_Player &user_player);
        //argument constructor
        User_Player(char * name, Board &board);
        ~User_Player(); 

        void display();
        void query_dictionary(const Board &board);

    protected:
        int score;
        char * name;


};
