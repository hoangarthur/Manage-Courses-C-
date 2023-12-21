#include "CourseList.h"

#include <iostream>
using namespace std;

// Copy constructor
CourseList::CourseList(const CourseList& newCourselist)
{
	if (newCourselist.count == 0) 
	{
		first = nullptr;
		last = nullptr;
		count = 0;
	}

	Node* current = newCourselist.first;
	while (current != nullptr)
	{
		addCourse(current->getCourse());
		current = current->getNext();
	}
}

// Definition overloaded assignment operator
CourseList& CourseList::operator=(const CourseList& newCourselist)
{
	if (this == &newCourselist) 
	{
		cerr << "Attempted assignment to itself." << endl;
	}
	else
	{
		if (newCourselist.count == 0)
		{
			clearList();
		}
		else if (count == 0)
		{
			copyCallingObjIsEmpty(newCourselist);
		}
		else if (count == newCourselist.count)
		{
			copyObjectsSameLength(newCourselist);
		}
		else if (count > newCourselist.count)
		{
			copyCallingObjLonger(newCourselist);
		}
		else
		{
			copyCallingObjShorter(newCourselist);
		}
	}
	return *this;
}

// Definition function copyCallingObjIsEmpty
void CourseList::copyCallingObjIsEmpty(const CourseList& newCourselist)
{
	Node* current = newCourselist.first;
	while(current != nullptr)
	{
		addCourse(current->getCourse());
		current = current->getNext();
	}
}

// Definition function copyObjectsSameLength
void CourseList::copyObjectsSameLength(const CourseList& newCourselist)
{
	Node* current = first;
	Node* currentNew = newCourselist.first;
	while(current != nullptr)
	{
		current->setCourse(currentNew->getCourse());
		current = current->getNext();
		currentNew = currentNew->getNext();
	}
}

// Definition function copyCallingObjLonger
void CourseList::copyCallingObjLonger(const CourseList& newCourselist)
{
	Node* current = first;
	Node* currentNew = newCourselist.first;
	while(currentNew != nullptr)
	{
		current->setCourse(currentNew->getCourse());
		last = current;
		current = current->getNext();
		currentNew = currentNew->getNext();
	}
	last->setNext(nullptr);

	while(current != nullptr)
	{
		Node* tempCurrent = current;
		current = current->getNext();
		deleteCourse(tempCurrent->getCourse().getCourseNumber());
	}
}

// Definition function copyCallingObjShorter
void CourseList::copyCallingObjShorter(const CourseList& newCourselist)
{
	Node* current = first;
	Node* currentNew = newCourselist.first;
	while(current != nullptr)
	{
		current->setCourse(currentNew->getCourse());
		current = current->getNext();
		currentNew = currentNew->getNext();
	}

	while(currentNew != nullptr)
	{
		addCourse(currentNew->getCourse());
		currentNew = currentNew->getNext();
	}
}
