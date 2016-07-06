// implementation for node.h


#include "node.h"

Node::Node(): word(NULL), left(NULL), right(NULL)
{
    
}

Node::Node(char * new_word): left(NULL), right(NULL)
{
    *word = *new_word;
}

Node::Node(const Node & node)
{
    copy_word(node.word, word);
}

Node::~Node()
{


}

void Node::display()
{

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

void Node::copy_word(char * source_word, char * & word)
{
    if(source_word == NULL)
        return;
    while(*source_word != '\0') 
    {
        *source_word = *word;
        source_word++;
        word++;
    }
}

Node* Node::go_left() const
{
    return left;
}

Node* Node::go_right() const
{
    return right;
}

