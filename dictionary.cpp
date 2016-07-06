//Implementation for dictionary header

#include "dictionary.h"

Dictionary::Dictionary()
{
    root = new Node();
    fill_tree(root);
}

//Dictionary::Dictionary(  )
//{


//}


Dictionary::Dictionary(const Dictionary & dictionary)
{
    copy_tree(root, dictionary.root);
}

Dictionary::~Dictionary()
{
   delete_all(root); 
}

void Dictionary::copy_tree(Node * & root, const Node * source_root)
{
   if(!source_root) 
       return;

   root = new Node(*source_root);
   copy_tree(root->go_left(), source_root->go_left());
   copy_tree(root->go_right(), source_root->go_right());

}

void Dictionary::delete_all(Node * root)
{
    if(!root)
        return;
    
    delete_all(root->go_left());
    delete_all(root->go_right());
    delete root;
}

void Dictionary::fill_tree(Node * root)
{

}

bool Dictionary::does_contain(char * word)
{


}

void Dictionary::display()
{

}
