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
        void copy_word(char *&word, char *source_word);
        Node *& get_left();
        // TODO the lab code has Node * & go_left()...
        Node *& get_right();

        //wrapper function to insert()
        bool insert_new_word(char *word);
        //wrapper function to find()
        bool find_word(char *word);

    protected:
        char *word;

        Node *parent;
        Node *left;
        Node *right;

        //recursive function to insert into tree
        void insert(char *word, Node *&);
        //recursive function to find, returns true if found
        bool find(char *word);

        int check_balance_factor();
        void rotate_left(Node *&root);
        void rotate_right(Node *&root);
        void balance_function(Node *&);

};
