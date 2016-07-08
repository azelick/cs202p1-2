// This is the main function for Program 1&2
// The program is a simplified scrabble game


#include<iostream>
#include "board.h"

using namespace std;

int main()
{
    
    Board playing_board = Board(5);

    cin.get();

    playing_board.display();

    cin.get();


    cout << "ending program" << endl;

}

