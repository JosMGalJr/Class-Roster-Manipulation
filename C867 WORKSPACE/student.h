#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;


/*Class intialization*/
class Student {
public:
	const static int daysInCourseArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[daysInCourseArraySize];
	DegreeProgram degreeProgram;

public:


	Student(); /*Constructor*/

	/*Initialization of accessors*/
	string GetStudentID();
	string GetFirstName();
	string GetLastName();
	string GetEmail();
	int GetAge();
	int* GetDaysInCourse();
	DegreeProgram GetDegreeProgram();

	/*Intitialization of mutators*/
	void SetStudentID(string studentID);
	void SetFirstName(string firstName);
	void SetLastName(string lastName);
	void SetEmail(string emailAddress);
	void SetAge(int age);
	void SetCourseLength(int daysInCourse[]);
	void SetDegreeProgram(DegreeProgram degreeProgram);

	static void printHeader();

	void print();

	/*Constructor with parameters*/
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);

	~Student(); /*Deconstructor*/




	





	
	

};
