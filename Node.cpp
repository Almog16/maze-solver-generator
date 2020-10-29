
#include <iostream>
using namespace std;
#include "Node.h"

Node::Node() //Constructor
{
    next=NULL;
}

Node::Node(Type item, Node* ptr) //Copy Constructor
{
    data=item;
    next=ptr;
}

//Insert newnode after current node
void Node::insertAfter(Node *newnode)
{
    newnode->next=next;
    next=newnode;
}

//Delete node after current node
Node *Node::DeleteAfter(void)
{
    Node *temp = next;
    if(next==NULL) return(NULL);
    next=temp->next;
    return(temp);
}
