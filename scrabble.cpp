// This is the main function for Program 1&2
// The program is a simplified scrabble game


#include <iostream>
#include "hand.h"

using namespace std;

int main()
{
    
    Board playing_board = Board(10);
    cin.get();

    playing_board.set_premium();
    Row_Space * space = playing_board.traverse_to_space(4,4);
    space->display();
    cout << endl;
    cin.get();

    playing_board.display();
    cin.get();

    Hand * hand = new Hand(playing_board);
    hand->draw_new_hand(playing_board);
    hand->display();
    cin.get();

    cout << "ending program" << endl;

}

