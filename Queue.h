/*
Queue Class impelemnts the static Queue data strcture with circled array
*/

using namespace std;
#ifndef Queue_h
#define Queue_h
#include "Point.h"

typedef Point Type;

class Queue
{
    private:
        unsigned int    size;
        int             head;
        int             tail;
        Type *          data;
        unsigned int      AddOne(unsigned int x);
    
    public:
        Queue(unsigned int rows, unsigned int cols);
        ~Queue();
        void            MakeEmpty();
        bool            IsEmpty(void);
        Type            Front(void);
        void            EnQueue(Type item);
        Type            DeQueue(void);

};

#endif


