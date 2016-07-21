// 

#import "user_player.h"

User_Player::User_Player()
{
}

User_Player::User_Player(const User_Player &user_player): Hand(user_player)
{
}

User_Player::User_Player(char * name, Board *&board): Hand(name, board)
{
}

void User_Player::query_dictionary(Board *&board)
{
   cout << "what word would you like to check? ";
   char temp[51]; 
   cin.get(temp, 50, '\n');
   cin.ignore(100, '\n');
   char * response = new char[strlen(temp) + 1];
   strcpy(response, temp);
   bool is_contained = board->check_word_is_valid(response);
   if(is_contained)
       cout << response << " is totally in the dictionary!" << endl;
   else
       cout << response << " is super not in the dictionary!" << endl;
}

char User_Player::get_user_choice()
{
    //show user board (probably done outside this function
    //show user's hand and score
    //maybe ask user what they would like to do, check dictionary or play word
    //ask user what they would like to play

    char response;
    do
    {
        cout << "It is your turn " << player_name << endl;
        cout << "What would you like to do?" << endl;
        cout << "Check word in dictionary? (D) " << endl;
        cout << "Play word from hand? (H) " << endl;
        cout << "Concede the game? (F) " << endl;
        cin >> response;
        cin.ignore(100, '\n');
        response = toupper(response);
    } while(again(response));
    return response;
}

bool User_Player::again(char response)
{
    if (response != 'D' && response != 'H' && response != 'F')
        return true;
    return false;
}

        
        
void User_Player::make_play(Board *&board)
{

    char choice = get_user_choice();
    if(choice == 'D')
    {
        query_dictionary(board);
    }
    else if (choice == 'H')
    {
        get_and_send_tiles_to_board(board);
    }
    else
    {
        cout << "once sec" << endl;
        //we do nothing, the ai takes a turn, then we can quit in the calling block.
    }
    //wait for the player here
    cin.get();
}

void User_Player::get_and_send_tiles_to_board(Board *&board)
{
    cout << "What word in your hand would you like to send to the board?" << endl;
    cout << "Lets do it letter by letter. " << endl;
    char letter;
    int x_coord;
    int y_coord;
    int turn_score = 0;
    do
    {
        cout << "What letter? ";
        cin >> letter;
        cin.ignore(20, '\n');
        letter = toupper(letter);
        cout << "What x coordinate? ";
        cin >> x_coord;
        cin.ignore(20, '\n');
        //so that it matches the index properly
        --x_coord;
        cout << "What y coordinate? ";
        cin >> y_coord;
        --y_coord;
        try
        {
            if(!contains_letter(letter))
                throw letter;
            place_tile_on_board(board, letter, x_coord, y_coord);
            turn_score += replace_tile(board, letter);
        }
        catch(char l) 
        {
            cout << "That letter doesn't exist in your hand";
        }

    } while(another_letter());
    score += turn_score;
    cout << "Your play was worth " << turn_score << " points";
}

bool User_Player::another_letter()
{
    char response;
    cout << "Would you like to play another tile? (Y)/(N) ";
    cin >> response;
    cin.ignore(20, '\n');
    response = toupper(response);

    if(response == 'Y')
        return true;
    return false;
}
