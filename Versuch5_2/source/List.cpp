/**
 * @file List.cpp
 * content: linked list data structure
 */

#include "List.h"

List::List(): head(NULL), tail(NULL)
{
}

/**
 * @brief Enqueue an element at the beginning of the list.
 *
 * @param pData The @ref Student to be added.
 * @return void
 */
void List::enqueue_head(const Student &pData)
{
    ListElem* new_element = new ListElem(pData, NULL,NULL);

    if (tail == NULL)                                       // list empty?
    {
        tail = new_element;
    }
    else
    {
        new_element->setNext(head);
        head->setBefore(new_element);
    }

    head = new_element;
}

/**
 * @brief Enqueue an element at the end of the list.
 *
 * @param pData The @ref Student to be added.
 * @return void
 */
void List::enqueue_tail(const Student &pData)
{
    ListElem* new_element = new ListElem(pData, NULL,NULL);

    if (tail == NULL)                                       // list empty?
    {
    	head = new_element;
    }
    else
    {
        tail->getBefore()->setNext(new_element);
        new_element->setBefore(tail->getBefore());
    }
    tail = new_element;
}

/**
 * @brief Dequeue an element from the end of the list.
 *
 * This is the single linked version.
 *
 * @param pData The data will be stored here.
 * @return bool
 */
bool List::dequeue(Student& pData)
{
    ListElem* cursor = head;

    if (head == NULL)                                       // list empty?
    {
        return false;
    }
    else if (head == tail)                                  // only one element
    {
        pData = head->getData();
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
    	//Search the element
        while (cursor->getNext() != tail)
        {
            cursor = cursor->getNext();
        }

        pData = tail->getData();
        tail = cursor;
        delete cursor->getNext();
        tail->setNext(NULL);
    }

    return true;
}

/**
 * @brief deletes an element by his matnr
 * @param pData the store object
 * @param nummer the matnr to look for
 * @return false if if deletion fails
 */
bool List::delElementByNr(Student& pData,unsigned int nummer)
{
	ListElem* cursor = head;

	// list empty?
    if (head == NULL)
    {
	    return false;
	}
    // only one element
	else if (head == tail)
	{
		if(head->getData().getMatNr() == nummer)
		{
			pData = head->getData();
			delete head;
			head = NULL;
			tail = NULL;
			return true;
		}
	}
	else
	{
		//Find element
		while (cursor->getNext()->getData().getMatNr() != nummer)
		{
			cursor = cursor->getNext();
			if(cursor == NULL) return false;
		}

		ListElem* before = cursor;
		//If element is in the middle
		if(cursor->getNext()->getNext() == NULL)
		{
			pData = cursor->getNext()->getData();
			delete cursor->getNext();
			before->setNext(NULL);
			tail = before;
			return true;
		}
		//If element is at the end
		else
		{
			ListElem* next = cursor->getNext()->getNext();
			pData = cursor->getNext()->getData();
			delete cursor->getNext();
			before->setNext(next);
			next->setBefore(before);
			return true;
		}
    }
    return true;
}

/**
 * @brief Print content from first to last element.
 *
 * Prints to cout.
 *
 * @return void
 */
void List::print_forwards()
{
    ListElem* cursor = head;

    while (cursor != NULL)
    {
        cursor->getData().print();

        cursor = cursor->getNext();
    }
}

/**
 * @brief Print content from last to first element.
 *
 * Prints to cout.
 *
 * @return void
 */
void List::print_backwards()
{
    ListElem* cursor = tail;

    while (cursor != NULL)
    {
        cursor->getData().print();

        cursor = cursor->getBefore();
    }
}
