//The Stack is implemented using a linked list of Nodes

#ifndef STACK_H
#define STACK_H

#include "Node.h"
#include "Point.h"

using namespace std;
typedef Point Type;

class Stack {
private:
	Node* top; //Points to top of stack

public:
	Stack();
	~Stack();
	void MakeEmpty(void);
	unsigned int IsEmpty(void);
	void Push(Type item);
	Type Pop(void);
};

#endif
