// 

#import <cstring>
#import "user_player.h"

User_Player::User_Player(): score(0), name(NULL)
{
}

User_Player::User_Player(const User_Player &user_player): Hand(user_player)
{
   score = user_player.score;
   if(!(user_player.name == NULL))
   {
        name = new char[(strlen(user_player.name) + 1)];
        strcpy(name, user_player.name);
   }
   else {name = NULL;}
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
    cout << "Player " << name;
    cout << " has the score: " << score << endl;
    Hand::display();
    //TODO
}

bool User_Player::query_dictionary(const Board &board)
{
   cout << "what word would you like to check? ";
   char * temp = new char[51];
   cin.get(temp, 50, '\0');
   cin.ignore(100, '\0');
   char * response = new char[strlen(temp) + 1];
   strcpy(response, temp);
    board.check_word_is_valid(response);

    
    //TODO When querying the dictionary, instead of transferring a bunch of tiles, we can just
    //turn the tiles into a char array and pass that
    //
}
