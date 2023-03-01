#pragma once
#include <iostream>
#include <string>
#include<student.h>
using namespace std;
using std::cout;

Student::Student(){}




/*Constructor with parameters*/
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this ->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysInCourse[0] = daysInCourse[0];
	this->daysInCourse[1] = daysInCourse[1];
	this->daysInCourse[2] = daysInCourse[2];
	this->degreeProgram = degreeProgram;
}

/*Accesssors*/
string Student::GetStudentID() {return this-> studentID;}
string Student::GetFirstName() {return this-> firstName;}
string Student::GetLastName() {return this-> lastName;}
string Student::GetEmail() {return this-> emailAddress;}
int Student::GetAge() {return this-> age;}
int* Student::GetDaysInCourse() {return this ->daysInCourse;}
DegreeProgram Student::GetDegreeProgram() {return this-> degreeProgram;}

/*Mutators*/
void Student::SetStudentID(string studentID) {this -> studentID = studentID;}
void Student::SetFirstName(string firstName) {this -> firstName = firstName;}
void Student::SetLastName(string lastName) {this -> lastName = lastName;}
void Student::SetEmail(string emailAddress) {this -> emailAddress = emailAddress;}
void Student::SetAge(int age) {this -> age = age;}
void Student::SetCourseLength(int days[]) {
	for (int index = 0; index < daysInCourseArraySize; index++) {
		this -> daysInCourse[index] = daysInCourse[index];
	}
}
void Student::SetDegreeProgram(DegreeProgram degree_Program) {degree_Program;}

/*Header for organization*/
void Student::printHeader()
{
	cout << "ID | First Name | Last Name | Email Address | Age | Days In Course (1, 2, 3) | Degree Program\n";
}

/*Prints student data*/
void Student::print(){
	cout << this->GetStudentID() << '\t';
	cout << this->GetFirstName() << '\t';
	cout << this->GetLastName() << '\t';
	cout << this->GetEmail() << '\t';
	cout << this->GetAge() << '\t';
	cout << this->GetDaysInCourse()[0] << '\t';
	cout << this->GetDaysInCourse()[1] << '\t';
	cout << this->GetDaysInCourse()[2] << '\t';
	cout << this->GetDegreeProgram() << '\t';
	cout << endl;
}
/*Deconstructor*/
Student::~Student() {};



