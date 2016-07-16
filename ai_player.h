//TODO Comments

#import "hand.h"
#import <iostream>

using namespace std;

class Ai_Player: public Hand
{

    public:
        Ai_Player();
        Ai_Player(const Ai_Player &user_player);
        Ai_Player(char * name);

        void display();
        //determine if the pieces in hand can be played
        bool is_play_in_hand();

        void make_play();


    protected:
        int score;


};
