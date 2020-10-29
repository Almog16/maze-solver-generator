//
//  Queue.cpp

#include <iostream>
using namespace std;
#include "Queue.h"

Queue::Queue(unsigned int rows, unsigned int cols)
{
    size=rows*cols;
    data=new Type [size];
    head = 1;
    tail = 0;
}

Queue::~Queue()
{
    delete[] data;
}

void Queue::MakeEmpty()
{
    head = 1;
    tail = 0;
}

unsigned int Queue::AddOne(unsigned int x)
{
    return((1+x) % size);
}

bool Queue::IsEmpty(void)
{
    return (AddOne(tail) == head);
}

Type Queue::Front(void)
{
    if(IsEmpty()){
        cout << "Error: QUEUE EMPTY\n";
        exit(1);
    }
    return(data[head]);
}

void Queue::EnQueue(Type item)
{
    if(AddOne(AddOne(tail))==head){
        cout << "Error: QUEUE FULL\n";
        exit(1);
    }
    tail = AddOne(tail);
    data[tail] = item;
}

Type Queue::DeQueue(void)
{
    if(IsEmpty()){
        cout << "Error: QUEUE EMPTY\n";
        exit(1);
    }
    Type item = data[head];
    head = AddOne(head);
    return(item);
}
