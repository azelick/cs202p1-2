//Implementation for dictionary header

#include "dictionary.h"

Dictionary::Dictionary()
{
    root = NULL;
}

//Dictionary::Dictionary(  )
//{


//}


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

void Dictionary::fill_tree()
{

}

bool Dictionary::does_contain(char *word)
{
    return root->contains(word);
}

void Dictionary::display()
{
    root->display();
}
