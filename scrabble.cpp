// This is the main function for Program 1&2
// The program is a simplified scrabble game


#include <iostream>
#include "hand.h"

using namespace std;

int main()
{
    
    Board *playing_board = new Board(10);
    cin.get();

    playing_board->set_premium();
    Row_Space * space = playing_board->traverse_to_space(4,4);
    space->display();
    cout << endl;
    cin.get();

    playing_board->display();
    cin.get();

    Hand * hand = new Hand(*playing_board);
    cout << "This is your hand: " << endl;
    hand->display();

    cout << "What letter would you like to put on the board? ";
    char input;
    int x, y;
    cin >> input;
    cout << "Where would you like to put it?" << endl
        << "x coordinate: ";
    cin >> x;
    cout << "Y coordinate: ";
    cin >> y;
    cout << endl;

    hand->place_tile_on_board(*playing_board, input, x-1, y-1);

    playing_board->display();


    delete playing_board;
    delete hand;
    cout << "ending program" << endl;

}

