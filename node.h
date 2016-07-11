// Node class for the Dictionaries binary search tree


#include<iostream>
#pragma once

using namespace std;

class Node
{
    public:
        //default constructor
        Node();
        //argument constructor
        Node(char *word);
        //copy constructor
        Node(const Node & node);
        //destructor
        ~Node();
        void display();
        int get_size();
        void copy_word(char *source_word, char * &word);
        bool contains(char *word);
        Node *& get_left();
        // TODO the lab code has Node * & go_left()...
        Node *& get_right();

    protected:
        char *word;

        Node *left;
        Node *right;

};
