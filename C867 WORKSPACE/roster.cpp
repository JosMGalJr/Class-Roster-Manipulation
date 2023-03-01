#pragma once
#include <roster.h>


void Roster::parse(string studentData) /*Parsing of student information*/
{
	int rSide = studentData.find(",");
	string studentID = studentData.substr(0, rSide);

	int lSide = rSide + 1;
	rSide = studentData.find(",", lSide);
	string firstName = studentData.substr(lSide, rSide - lSide);

	lSide = rSide + 1;
	rSide = studentData.find(",", lSide);
	string lastName = studentData.substr(lSide, rSide - lSide);

	lSide = rSide + 1;
	rSide = studentData.find(",", lSide);
	string email = studentData.substr(lSide, rSide - lSide);

	lSide = rSide + 1;
	rSide = studentData.find(",", lSide);
	int age = stoi(studentData.substr(lSide, rSide - lSide));

	lSide = rSide + 1;
	rSide = studentData.find(",", lSide);
	int daysInCourse1 = stoi(studentData.substr(lSide, rSide - lSide));

	lSide = rSide + 1;
	rSide = studentData.find(",", lSide);
	int daysInCourse2 = stoi(studentData.substr(lSide, rSide - lSide));

	lSide = rSide + 1;
	rSide = studentData.find(",", lSide);
	int daysInCourse3 = stoi(studentData.substr(lSide, rSide - lSide));

	lSide = rSide + 1;
	rSide = studentData.find(",", lSide);
	DegreeProgram degreeProgram = DegreeProgram::SECURITY;
	if (studentData.substr(lSide, rSide - lSide) == "NETWORK") degreeProgram = DegreeProgram::NETWORK;
	else if (studentData.substr(lSide, rSide - lSide) == "SOFTWARE") degreeProgram = DegreeProgram::SOFTWARE;

	

	add(studentID, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);

}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysInCourseArray[3] = { daysInCourse1, daysInCourse2, daysInCourse3 };
	classRosterArray[++studentIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourseArray, degreeProgram);
}

/*Prints out a header and all student data*/ /*EDITED: Now calls print() function defined in "Student" class to handle student data output*/
void Roster::printAll()
{
	Student::printHeader();
	for (int i = 0; i <= Roster::studentIndex; i++)
	{
		classRosterArray[i]->print();

		/*cout << classRosterArray[i]->GetStudentID(); cout << '\t';
		cout << classRosterArray[i]->GetFirstName(); cout << '\t';
		cout << classRosterArray[i]->GetLastName(); cout << '\t';
		cout << classRosterArray[i]->GetEmail(); cout << '\t';
		cout << classRosterArray[i]->GetAge(); cout << '\t';
		cout << classRosterArray[i]->GetDaysInCourse()[0]; cout <<'\t';
		cout << classRosterArray[i]->GetDaysInCourse()[1]; cout <<'\t';
		cout << classRosterArray[i]->GetDaysInCourse()[2]; cout << '\t';
		cout << classRosterArray[i]->GetDegreeProgram() << endl;*/
	}
}

/*Prints students who are ONLY in a specified degree program*/
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	Student::printHeader();
	for (int i = 0; i <= Roster::studentIndex; i++) {
		if (Roster::classRosterArray[i]->GetDegreeProgram() == degreeProgram) classRosterArray[i]->print(); cout << endl;
	}

	
	cout << endl;
}

/*Detects invalid email addresses and prints them*/
void Roster::printInvalidEmails()
{
	bool alert = false;
	for (int i = 0; i <= Roster::studentIndex; i++)
	{
		string emailAddress = (Roster::classRosterArray[i]->GetEmail());
		if (emailAddress.find('@') == string::npos || (emailAddress.find('.') == string::npos || (emailAddress.find(' ') != string::npos)))
		{
			alert = true;
			cout << classRosterArray[i]->GetStudentID() << ": " << emailAddress << endl;
		}
	}
	if (!alert) cout << "NONE" << endl;
}

/*Gets the average days in courses for each student*/
void Roster::printAverageDaysInCourse(string studentID)
{
	for (int i = 0; i <= Roster::studentIndex; i++) {
		cout << classRosterArray[i]->GetStudentID() << ": ";
		cout << (classRosterArray[i]->GetDaysInCourse()[0] + classRosterArray[i]->GetDaysInCourse()[1] + classRosterArray[i]->GetDaysInCourse()[2]) / 3 << endl;
			
	}
	cout << endl;
}

/*Removal of "studentID" and information pertaining to them*/
void Roster::remove(string studentID)
{
	bool success = false;
	for (int i = 0; i <= Roster::studentIndex; i++)
	{
		if (classRosterArray[i]->GetStudentID() == studentID)
		{
			success = true;
			if (i < totalStudents - 1)
			{
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[totalStudents - 1];
				classRosterArray[totalStudents - 1] = temp;
			}
			Roster::studentIndex--;
		}
	}
	if (success)
	{
		cout << studentID << "deleted." << endl << endl;
		this->printAll();
	}
	else cout << studentID << " not found." << endl << endl;
}

/*Frees up memory*/
Roster::~Roster()
{
	for (int i = 0; i < totalStudents; i++)
	{
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}
