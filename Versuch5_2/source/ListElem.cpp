/**
 * @file ListElem.cpp
 *
 * content: List element to be used in a data structure
 */

#include "ListElem.h"

ListElem::ListElem(const Student &s, ListElem* const q):
    data(s), next(q)
{
}

/**
 * @brief sets the Data(student) of the list Element
 * @param s the student
 */
void ListElem::setData(const Student &s)
{
    data = s;
}

/**
 * @brief sets the pointer to the next list element
 * @param q pointer to list element
 */
void ListElem::setNext(ListElem* const q)
{
    next = q;
}


/**
 * @brief returns the student which is saved in the list element
 * @return the student
 */
Student ListElem::getData() const
{
    return data;
}


/**
 * @brief returns the pointer to the next list element
 * @return pointer to next list element
 */
ListElem* ListElem::getNext() const
{
    return next;
}
