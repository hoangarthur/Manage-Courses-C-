#ifndef COURSELIST_H
#define COURSELIST_H

#include "Course.h"

#include <string>
#include <set>

class Node
{
public:
	Node() : course(), next(nullptr) {}
	Node(const Course &newCourse, Node *newNext)
		: course(newCourse), next(newNext) {}
	Course getCourse() const { return course; }
	Node *getNext() const { return next; }
	void setCourse(const Course &newCourse) { course = newCourse; }
	void setNext(Node *newNext) { next = newNext; }
	~Node() {}

private:
	Course course;
	Node *next;
};

class CourseList
{
public:
	// Default constructor
	CourseList()
	{
		count = 0; 
		first = nullptr; 
		last = nullptr;
	};

	// Functions addCourse
	void addCourse(const Course&);
	void addCourse(int, const std::string &, int, const std::set<int> &);
	
	// Accessor functions
	std::string getPrefix();
	int getNumberOfCourses();

	// Boolean functions
	bool isEmpty() const;

	// Function deleteCourse
	void deleteCourse(int);

	// Function retrieveAllCourses
	bool searchCourse(int);
	bool searchCourse(int, std::string &);
	bool searchCourse(int, Course &);
	void retrieveAllCourses(std::string &);
	
	// Function clearList
	void clearList();

	/********************* THE BIG THREE *********************/

	// Copy constructor
	CourseList(const CourseList &);

	// Overloaded assignment operator
	CourseList &operator=(const CourseList &);

	// Destructor
	~CourseList()
	{
		if (count != 0)
			clearList();
	}

private:
	// Function getCourseLocation
	Node *getCourseLocation(int);

	// Function addInOrder
	void insertInOrder(Node *);

	// Helper functions for overloaded assignment operator
	void copyCallingObjIsEmpty(const CourseList &);
	void copyObjectsSameLength(const CourseList &);
	void copyCallingObjLonger(const CourseList &);
	void copyCallingObjShorter(const CourseList &);
	Node *first;
	Node *last;
	int count;
};
#endif