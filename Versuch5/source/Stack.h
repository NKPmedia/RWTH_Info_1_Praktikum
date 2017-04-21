#ifndef STACK_H_
#define STACK_H_

#include <iostream> /* cin/cout */
#include "ListElem.h"

class Stack
{
private:
    ListElem* head;
    ListElem* tail;

public:
    Stack();
    void push(Student& newElement);
    bool pop(Student& student);
    void ausgabe() const;
};

#endif
