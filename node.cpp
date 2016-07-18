// implementation for node.h

#include "node.h"

Node::Node(): word(NULL), height(0), left(NULL), right(NULL)
{
    
}

Node::Node(char * new_word): height(0), left(NULL), right(NULL)
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
    cout << word << endl;
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
        //we're at a leaf
        root = new Node(new_word);
        cout << "insertion has occurred" << endl; 
    }
    else
    {
        int compare = strcmp(new_word, root->word);
        if (compare < 0)
        {
            root->left->insert(new_word, root->left);
        }
        if (compare >= 0)
        {
            root->right->insert(new_word, root->right);
        }
    }
    balance_function(root);
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

int Node::calculate_height(Node *root)
{
    if (!root)
        return 0;
    root->height = max(calculate_height(root->left), calculate_height(root->right)) + 1;
    return root->height;
}

int Node::get_balance(Node *root)
{
    if(root)
        return calculate_height(root->left) - calculate_height(root->right);
    return 0;
}

void Node::balance_function(Node *&root)
{
    if(!root)
        return;

    int balance_factor = get_balance(root);

    cout << "balance_factor at : " << root->word 
        << " is " << balance_factor << endl;

    if(balance_factor == 2)
    {
        int left_balance = get_balance(root->left);
        //left has more than right
        //so left should become root
        if(left_balance == 0)
        {
            cout << "this shouldn't happen, if it does we have a problem" << endl;

        }
        if(left_balance == 1)
        {
            rotate_clockwise(root);
        }
        if(left_balance == -1)
        {
            rotate_counter_clockwise(root->left);
            rotate_clockwise(root);
        }
    }
    if(balance_factor == -2)
    {
        int right_balance = get_balance(root->right);
        //right has more than left
        if(right_balance == 0)
        {
            cout << "this shouldn't happen, if it does we have a problem" << endl;
        }
        if(right_balance == 1)
        {
            rotate_clockwise(root->right);
            rotate_counter_clockwise(root);
        }
        if(right_balance == -1)
        {
            rotate_counter_clockwise(root);
        }
    } 
    return;
}

void Node::rotate_counter_clockwise(Node *&root)
{
    Node * temp = root;
    root = temp->right;
    temp->right = root->left;
    root->left = temp;
    calculate_height(root);
    calculate_height(temp);
    cout << "rotation left";
}

void Node::rotate_clockwise(Node *&root)
{
    Node * temp = root;
    root = temp->left;
    temp->left = root->right;
    root->right = temp;
    calculate_height(root);
    calculate_height(temp);
    cout << "rotation right";
}
