//TODO Comments

#import "hand.h"
#import <iostream>

using namespace std;

class Ai_Player: public Hand
{

    public:
        Ai_Player();
        Ai_Player(const Ai_Player &user_player);
        Ai_Player(const char * name, Board *board);
        ~Ai_Player();

        void make_play(Board *board);

    protected:
        //determine if the pieces in hand can be played
        void find_plays_in_hand(Board *board);
};
