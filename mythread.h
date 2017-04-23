#ifndef MYTHREAD_H
#define MYTHREAD_H
#include <QThread>
#include "mylist.h"
#include "book.h"

void push_back(myList *L,std::shared_ptr<book> B) ;
void pop_back(myList *L);
void pop_front(myList *L);

class myThread : public QThread
{
Q_OBJECT
public:
    
    void run()
    {
        for(int i=0;i<2;i++)
                {
                 emit Signal(i);
                 usleep(20000);
                 i=0;
                }
     }

signals: 
    void Signal(int);
};

#endif // MYTHREAD_H
