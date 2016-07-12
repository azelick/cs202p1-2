// This is the tile header file
// The job of the tile class is to contain a letter
// and to know how many points the letter is worth 
// besides the accessor functions this class can display itsself

#include<iostream>

using namespace std;

#pragma once

class Tile
{
	public: 
        Tile();
        Tile(char new_letter, int new_point_value);
        ~Tile();
        //display the letter and point value
		void display();
        void set_letter(char new_letter);
        void set_point_value(int new_value);
        char get_letter();
        int get_point_value();
        //copy this tile into the provided tile 
        void copy_tile(Tile * tile) const;

	protected:
		char letter;
		int point_value;

};
