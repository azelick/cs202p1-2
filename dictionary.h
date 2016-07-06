//This is the dictionary class
//It is responsible for loading a file of words into memory
//then it can perform checks to make sure a provided word
//matches the list of words it contains
//


#include <iostream>
#include "node.h"

using namespace std;

class Dictionary
{
    public:
        // Default constructor
        Dictionary();
        // TODO
        // argument constructor
        //Dictionary( );
        // copy constructor
        Dictionary(const Dictionary & dictionary);
        // Destructor
        ~Dictionary();

        // Recursive function to copy the BST
        void copy_tree(Node * & root, const Node * source_root);

        // destructor method for the BST
        void delete_all(Node * root);

        // populates the tree from file
        void fill_tree(Node * root);

        //check to see if the dictionary contains the provided word
        bool does_contain(char * word);
        // TODO Don't know if I want the dictionary to be able
        // to oubput the entire tree or not...
        // Depends on the size of the data?
        void display();

    protected:
        // the root of the dictionary's binary search tree
        Node * root;

};
