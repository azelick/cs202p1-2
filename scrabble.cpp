// This is the main function for Program 1&2
// The program is a simplified scrabble game


#include <iostream>
#include "user_player.h"
#include "ai_player.h"
#include <cstdlib>
#include <ctime>

using namespace std;

bool again();

int main()
{
    //gives us random numbers for the shuffle
    srand(time(NULL));
    
    Board *playing_board = new Board(10);
    playing_board->set_premium();
    playing_board->display();
    
    Hand *player_a;
    Hand *player_u;

    cout << "Welcome to scrabble! " << endl;
   cout << "Please enter a player name: ";
   char input[100];
   cin.get(input, 100, '\n');
   cin.ignore(100, '\n');

   player_u = new User_Player(input, playing_board);
   player_a= new Ai_Player("AI man", playing_board);

   bool player_wins = false;
    do
    {   
        cout << "This is the AI hand: " << endl;
        player_a->display();
        
        cout << "This is the player's hand " << endl;
        player_u->display();

        //user goes first
        player_u->make_play(playing_board);
        //ai goes second
        player_a->make_play(playing_board);

        playing_board->display();
        if(player_u->get_score() > 5 || player_a->get_score() > 5)
        {player_wins = true;}
    }while(!player_wins && again());



    player_a->make_play(playing_board);

    //Coordinate loc = playing_board->find_playable_location(hand->head->word);

//    hand->place_tile_on_board(*playing_board, input, x-1, y-1);

    playing_board->display();


    delete playing_board;
    cout << "ending program" << endl;

}

bool again()
{
    cout << "Would you like to concede? (Y), (N) " << endl;
    char response;
    cin >> response;
    cin.ignore(100, '\n');
    
    response = toupper(response);

    if(response == 'Y')
        return false;
    return true;
}
