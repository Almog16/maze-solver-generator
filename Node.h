//A Node is part of a linked list of Nodes
//Note: Data is public

using namespace std;
#ifndef Node_h
#define Node_h
#include "Point.h"

typedef Point Type;

class Node
{
    public:
    Type data; //data field
    Node *next; //pounsigned ints to next node in list
    Node();
    Node(Type item, Node *ptr=NULL);
    //~Node();
    void insertAfter(Node* newnode); //Insert newnode after current node
    Node* DeleteAfter(void); //Delete node after current node


};

#endif


