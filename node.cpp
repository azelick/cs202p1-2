// implementation for node.h

#include "node.h"

Node::Node(): word(NULL), parent(NULL), left(NULL), right(NULL)
{
    
}

Node::Node(char * new_word): parent(NULL), left(NULL), right(NULL)
{
    word = new char[strlen(new_word) + 1];
    strcpy(word, new_word);
}

Node::Node(const Node & node)
{
    //TODO Do I need an initialization list?
    copy_word(word, node.word);
}

Node::~Node()
{
    if(left)
        delete left;
    if(right)
        delete right;
}

void Node::display()
{
    if(!word)
        return;
    int i = 0;
    while(word[i] != '\0')
    {
        cout << word[i];
        ++i;
    }
    cout << endl;

    if(left) 
        left->display();
    if(right)
        right->display();
}

int Node::get_size()
{
    if(word == NULL)
        return 0;
    if(*word == '\0')
        return 0;
    int size = 0;
    do
    {
        size++;
        word++;
    } while(*word != '\0');
    return size;
}

void Node::copy_word(char *&word, char *source_word)
{
    if(source_word == NULL)
        return;
    
    word = new char[strlen(source_word) + 1];
    strcpy(word, source_word);
}

Node *& Node::get_left()
{
    return left;
}

Node *& Node::get_right()
{
    return right;
}

bool Node::insert_new_word(char *word)
{
    //this should be called on the dummy node that contains the whole tree on it's left pointer
    insert(word, left);
    return true;
}

bool Node::find_word(char *word)
{
    //we have no tree
    if (!left)
        return false;
    return left->find(word);
}

void Node::insert(char *new_word, Node *&root)
{
    if(!root)
    {
        root = new Node(new_word);
        root->left = NULL;
        root->right = NULL;
        return;
    }
    else
    {
        int compare = strcmp(root->word, new_word);
        if (compare < 0)
        {
            if(!left)
                left = new Node(new_word);
            else
                left->insert(new_word, root->left);
        }
        if (compare >= 0)
        {
            if(!right)
                right = new Node(new_word);
            else
                right->insert(new_word, root->right);
        }
    }
    root->balance_function(root);
   
}

bool Node::find(char * matcher_word)
{
    int comparison = strcmp(word, matcher_word);
    if(comparison == 0)
        return true;
    if(comparison < 0)
    {
        if (!left)
            return false;
        return left->find(matcher_word);
    }
    if(!right)
        return false;
    return right->find(matcher_word);
}

int Node::check_balance_factor()
{
    int balance_factor = 0;
    if(left)
        balance_factor += left->check_balance_factor() + 1;
    if(right)
        balance_factor -= right->check_balance_factor() - 1;
    return balance_factor;    
}

void Node::balance_function(Node *&root)
{
    int balance_factor = check_balance_factor();

    if(balance_factor == 2)
    {
        int left_factor = left->check_balance_factor();

        //left has more than right
        //so left should become root
        if(left_factor == 0)
        {
            cout << "this shouldn't happen, if it does we have a problem" << endl;

        }
        if(left_factor == 1)
        {
            rotate_right(root);
        }
        if(left_factor == -1)
        {
            left->rotate_left(left);
            rotate_right(root);
        }
    }
    if(balance_factor == -2)
    {
        //right has more than left
        int right_factor = right->check_balance_factor();

        if(right_factor == 0)
        {
            cout << "this shouldn't happen, if it does we have a problem" << endl;
        }
        if(right_factor == 1)
        {
            right->rotate_right(right);
            rotate_left(root);
        }
        if(right_factor == -1)
        {
            rotate_left(root);
        }
    } 
}

void Node::rotate_left(Node *&root)
{
    root = root->right;
    right = root->left;
    root->left = this;
}

void Node::rotate_right(Node *&root)
{
    root = root->left;
    left = root->right;
    root->right = this;
}
