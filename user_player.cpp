// 


#import "user_player.h"

User_Player::User_Player(): score(0), name(NULL)
{

}

User_Player::User_Player(const User_Player &user_player): Hand(user_player)
{
    
}

User_Player::User_Player(char * name, Board &board) throw(NULL_NAME): Hand(board)
{
   if(!name) 
   {
       NULL_NAME error;
       error.name = NULL;
       throw error;
   }
}

void User_Player::display()
{

}

void User_Player::query_dictionary(const Board &board)
{
    //TODO When querying the dictionary, instead of transferring a bunch of tiles, we can just
    //turn the tiles into a char array and pass that
    //
}
