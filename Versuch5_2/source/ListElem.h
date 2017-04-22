/**
 * @file ListElem.h
 *
 * content: List element to be used in a data structure
 */

#ifndef _LISTELEM_H_
#define _LISTELEM_H_

#include "Student.h"

class ListElem
{
private:
	Student data;
    ListElem* next;
    ListElem* before;

public:
    ListElem(const Student &s, ListElem* const q, ListElem* const w);

    void setData(const Student &s);
    void setNext(ListElem* const q);
    void setBefore(ListElem* const q);

    Student getData() const;
    ListElem* getNext() const;
    ListElem* getBefore() const;
};

#endif
