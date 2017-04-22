#include "Stack.h"

Stack::Stack(): head(NULL), tail(NULL)
{
}

/**
 * @brief pushes a Student on the stack
 * @param newElement the new student
 *
 * Puts a new Student at the top of the list
 */
void Stack::push(Student& newElement)
{
	ListElem* element = new ListElem(newElement,NULL,NULL);
	if(head == NULL)
	{
		tail=element;
	}
	else
	{
		element->setNext(head);
	}
	head = element;
}

/**
 * @brief prints information about every student in the stack
 */
void Stack::ausgabe() const
{
	if(head == NULL) // list empty?
	{
		std::cout << "Der Stack ist leer." << std::endl;
	}
	else
	{
		ListElem* cursor = head;

		while(cursor != NULL)
		{
			cursor->getData().print();
			cursor = cursor->getNext();
		}
	}
}

/**
 * @brief pop a student from the stack
 * @param student
 * @return false if the stack is empty
 *
 * Returns false if the stack is empty.
 * Otherwise it returns the student at the top of the list
 */
bool Stack::pop(Student& student)
{
    if (head == NULL)
    { 	//list empty???
        return false;
    }
    else
    {
        student = head->getData();
        ListElem* cursor = head;
        head = head->getNext();
        delete cursor;
    }
    return true;
}
