
#include "CourseList.h"

// Definition function insertInOrder
// Assume there are no duplicates.
void CourseList::insertInOrder(Node* otherNode)
{
	if(first == nullptr)
	{
		first = otherNode;
		last = first;
	}
	else
	{
		last->setNext(otherNode);
		last = otherNode;
	}
	++count;

	Node* current = first;
	while(current != nullptr)
	{
		Node* currentNext = current->getNext();
		while(currentNext != nullptr)
		{
			if((current->getCourse().getCourseNumber()) 
				> (currentNext->getCourse().getCourseNumber()))
			{
				Course temp = currentNext->getCourse();
				currentNext->setCourse(current->getCourse());
				current->setCourse(temp);
			}
			currentNext = currentNext->getNext();
		}
		current = current->getNext();
	}
}