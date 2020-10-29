#include <iostream>
using namespace std;
#include "Stack.h"

Stack::Stack() // Constructor: initialize top
{
	top = nullptr;
}

Stack::~Stack() // Destructor: free memory
{
	MakeEmpty();
}

unsigned int Stack::IsEmpty(void)
{
	return(top == nullptr);
}

void Stack::MakeEmpty(void) // MakeEmpty: make stack empty
{
	Node *temp;
	while (top != nullptr)
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}

void Stack::Push(Type item) // Push: push item onto stack
{
	top = new Node(item,top);
}

Type Stack::Pop(void) // Pop: pop top item and return it
{
	if (IsEmpty()) {
		cout << "Error:STACK UNDERFLOW\n"; exit(1);
	}
	Node *temp = top;
	Type item = top->data;
	top = top->next;
	delete temp;
	return(item);
}