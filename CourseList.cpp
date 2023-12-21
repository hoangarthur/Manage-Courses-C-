#include "CourseList.h"

#include <iostream>
using namespace std;

// Definition function addCourse
void CourseList::addCourse(const Course& newCourse)
{
	insertInOrder(new Node(newCourse, nullptr));
};

// Definition function addCourse
void CourseList::addCourse(int newCourseNumber, 
							const std::string& newCourseName, 
							int newCourseUnits, 
							const std::set<int>& newPrereqs)
{
	insertInOrder(
		new Node(Course(
			newCourseNumber, 
			newCourseName, 
			newCourseUnits, 
			newPrereqs), 
			nullptr));
};

// Definition function getPrefix
string CourseList::getPrefix()
{
	return Course::getPrefix();
};

// Definition function getNumberOfCourses
int CourseList::getNumberOfCourses()
{
	return count;
};

// Definition function isEmpty
bool CourseList::isEmpty() const
{
	return (count == 0);
};

// Definition function searchCourse (courseNumber)
// Assume list is non-empty.
bool CourseList::searchCourse(int courseNumber)
{
	return (getCourseLocation(courseNumber) != nullptr);
}

// Definition function searchCourse (courseNumber, courseName)
// Assume list is non-empty.
bool CourseList::searchCourse(int courseNumber, std::string& courseName)
{
	if (getCourseLocation(courseNumber) != nullptr)
	{
		courseName = getCourseLocation(
			courseNumber)->getCourse().getCourseName();
		return true;
	}
	return false;
}

// Definition function searchCourse(courseNumber, course)
// Assume list is non-empty.
bool CourseList::searchCourse(int courseNumber, Course& course)
{
	if (getCourseLocation(courseNumber) != nullptr)
	{
		course = getCourseLocation(courseNumber)->getCourse();
		return true;
	}
	return false;
}

// Definitiion deleteCourse
// Assume list is non-empty.
// Assume course is in the list.
void CourseList::deleteCourse(int courseNumber)
{
	if (first->getCourse().getCourseNumber() == courseNumber)
	{
		Node* current = first;
		first = first->getNext();
		delete current;
		current = nullptr;
		--count;
	}
	else
	{
		Node* trailCurrent = first;
		Node* current = first->getNext();
		while (current != nullptr)
		{
			if (current->getCourse().getCourseNumber() == courseNumber)
			{
				trailCurrent->setNext(current->getNext());
				delete current;
				current = nullptr;
				--count;
			}
			else
			{
				trailCurrent = current;
				current = current->getNext();
			}
		}
	}
}

// Definition retrieveAllCourses
// Assume list is non-empty.
void CourseList::retrieveAllCourses(string& strRetrieve) // CS A150 - C++ 1
{
	strRetrieve = "";
	Node* current = first;
	while(current != nullptr)
	{
		strRetrieve += current->getCourse().getPrefix()
			+ std::to_string(current->getCourse().getCourseNumber())
			+ " - " + current->getCourse().getCourseName() + "\n";
		current = current->getNext();
	}
}

// Definition clearList
void CourseList::clearList()
{
	Node* current = first;
	while (first != nullptr)
	{
		first = first->getNext();
		delete current;
		current = first;
	}
	count = 0;
}

// Definition function getCourseLocation
Node* CourseList::getCourseLocation(int courseNumber)
{
	Node* current = first;
	bool found = false;
	while(current != nullptr && !found)
	{
		if(current->getCourse().getCourseNumber() == courseNumber)
		{
			found = true;
		}
		else
			current = current->getNext();
	}
	return (found ? current : nullptr);
};