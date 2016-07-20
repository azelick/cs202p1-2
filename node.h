// Node class for the Dictionaries binary search tree


#include<iostream>
#include "structs.h"
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
        void copy_word(char *&word, char *source_word);
        Node *& get_left();
        // TODO the lab code has Node * & go_left()...
        Node *& get_right();

        //wrapper function to insert()
        bool insert_new_word(char *word);
        //wrapper function to check if word in in dict
        bool find_word(char *word);
        //recursive function the return LLL of all words in
        //dict that contain given letter
        void find_words(Dict_Word *&tail, Node *root, const char letter);

    protected:
        char *word;
        int height;

        Node *left;
        Node *right;

        //recursive function to insert into tree
        void insert(char *word, Node *&);
        //recursive function to find, returns true if found
        bool find(Node * root, char *word);

        int get_balance(Node *root);
        int calculate_height(Node *root);
        void rotate_counter_clockwise(Node *&root);
        void rotate_clockwise(Node *&root);
        void balance_function(Node *&);

};
