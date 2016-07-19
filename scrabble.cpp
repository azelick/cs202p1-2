// This is the main function for Program 1&2
// The program is a simplified scrabble game


#include <iostream>
#include "hand.h"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //gives us random numbers for the shuffle
    srand(time(NULL));
    
    Board *playing_board = new Board(10);
    cin.get();
    
    //cout << "Here is the dictionary: " << endl;
    //playing_board->display_dictionary();

    cin.get();

    char * test_word = new char[2];
    test_word[0] = 'A';
    test_word[1] = '\0';
    //if (playing_board->check_word_is_valid(test_word))
    //    cout << "The word '" << test_word << "' is in the dictionary" << endl;


    playing_board->set_premium();
//    Row_Space * space = playing_board->traverse_to_space(4,4);
//    space->display();
//    cout << endl;
    //playing_board->display_dictionary();
    cin.get();

    playing_board->display();
    cin.get();

    Hand * hand = new Hand(*playing_board);
    cout << "This is your hand: " << endl;
    hand->display();
    
    cin.get();
    cout << "before grooming: " << endl;
    char first_letter = (hand->get_hand())[0];
    Dict_Word * list = playing_board->find_words_with_letter(first_letter);
    hand->set_dict_match_list(list);
    hand->display_possibles_list();

    cout << "After grooming: " << endl;
    cin.get();
    hand->groom_for_playable_words();
    hand->display_possibles_list();
    

//    hand->place_tile_on_board(*playing_board, input, x-1, y-1);

    playing_board->display();


    delete playing_board;
    delete hand;
    cout << "ending program" << endl;

}

