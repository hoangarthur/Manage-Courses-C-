#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <set>

class Course
{
public:
	// Constructors
	Course() :courseNumber(0), courseName("N/A"), courseUnits(0){};
	Course(int, const std::string&,int, const std::set<int>& );
	// Accessor functions
	std::string const &getCourseName() const;
	int getCourseNumber() const;
	int getCourseUnits() const;
	std::set<int> const & getCoursePrereqs() const;
	Course const& getCourse() const;
	static std::string getPrefix();
	
	// Mutator functions
	void setCourseName(const std::string& );
	void setCourseNumber(int);
	void setCourseUnits(int);
	void setPrereqs(const int [], int);
	
	// Destructor
	~Course(){};
private:
	int courseNumber;
	std::string courseName;	
	int courseUnits;	
	std::set<int> prereqs;
	static const std::string PREFIX;
};
#endif