//Implementation for dictionary header

#include "dictionary.h"

Dictionary::Dictionary()
{
    //this will create our dummy node
    root = new Node();
    fill_tree_from_file();
}

Dictionary::Dictionary(const Dictionary &dictionary)
{
    copy_tree(root, dictionary.root);
}

Dictionary::~Dictionary()
{
    if(root)
        delete root;
}

void Dictionary::copy_tree(Node * &root, Node *source_root)
{
   if(!source_root) 
       return;

   root = new Node(*source_root);
   copy_tree(root->get_left(), source_root->get_left());
   copy_tree(root->get_right(), source_root->get_right());

}

void Dictionary::display()
{
    root->get_left()->display();
}

void Dictionary::fill_tree_from_file()
{
    if (!root)
        root = new Node();

    int file_size;
    ifstream reader;
    reader.open("dict.txt", ifstream::in);

    //to aboid using the eof flag, I'm including the number of lines in the file on the first line
    reader >> file_size;

    reader.ignore(100, '\n');

    for(int i = 0; i < file_size; ++i)
    {
        char * temp;
        char from_file[100];
        reader.get(from_file, 100, '\n');
        reader.ignore(100, '\n');

        temp = new char[strlen(from_file) + 1];
        strcpy(temp, from_file);

        root->insert_new_word(temp);
    }
    reader.close();
}

bool Dictionary::does_contain(const char *word)
{
    int i = 0;
    char * mutable_word = new char[strlen(word) + 1];
    while(word[i] != '\0')
    {
        mutable_word[i] = toupper(word[i]);
        ++i;
    }
    return root->find_word(mutable_word);
}
