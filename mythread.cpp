#include "mythread.h"


void push_back(myList *L, std::shared_ptr<book> B)
{
    L->push_back(B);
}


void pop_back(myList *L)
{
    L->pop_back();
}

void pop_front(myList *L)
{
    L->pop_front();
}
