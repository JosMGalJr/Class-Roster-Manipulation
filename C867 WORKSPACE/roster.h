#include<student.h>

/*Class initialization*/
class Roster {


public:
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void parse(string studentData);

	/*Declared so that the array is accessed from 0*/
	int studentIndex = -1;
	
	const static int totalStudents = 5;
	Student* classRosterArray[totalStudents];

	/*Deconstructor*/
	~Roster();
};




