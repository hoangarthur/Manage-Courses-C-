#include "Course.h"

#include <iostream>
#include <iomanip>
using namespace std;

const string Course::PREFIX = "CS A";

// Definition overloaded constructor

Course::Course(int newCourseNumber, 
			const string& newCourseName, 
			int newCourseUnits, 
			const set<int>& newPrereqs)
{
	courseNumber = newCourseNumber;
	courseName = newCourseName;
	courseUnits = newCourseUnits;
	prereqs = newPrereqs;
};

// Definition function getCourseNumber
int Course::getCourseNumber() const
{
	return courseNumber;
};

// Definition function getCourseName
string const& Course::getCourseName() const
{
	return courseName;
};

// Definition function getCourseUnits
int Course::getCourseUnits() const
{
	return courseUnits;
};

// Definition function getPrereqs
set<int> const& Course::getCoursePrereqs() const
{
	return prereqs;
};

// Definition function getCourse
Course const& Course::getCourse() const
{
	return *this;
};

// Definition function getPrefix
string Course::getPrefix()
{
	return PREFIX;
};

// Definition function setCourseName
void Course::setCourseName(const string& newCourseName)
{
	courseName = newCourseName;
};

// Definition function setCourseNumber
void Course::setCourseNumber(int NewCourseNumber)
{
	courseNumber = NewCourseNumber;
};

// Definition function setCourseUnits
void Course::setCourseUnits(int NewCourseUnits)
{
	courseUnits = NewCourseUnits;
};

// Definition function setPrereqs
void Course::setPrereqs(const int newPrereqs[], int sizeArray)
{
	prereqs.clear();
	for (int i = 0; i < sizeArray; i++)
	{
		prereqs.insert(newPrereqs[i]);
	}
};


