#include <iostream>
#include <string>
#include <roster.h>
using namespace std;


int main()
{
    cout << "Scripting and Programming - Applications - C867 | C++| #000930310 | Jose Galarza" << endl;

    /*All data that will be read and utilized*/
    const string studentData[] =

    {"A1,John,Smith,John1989@g mail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Jose,Galarza,jgalar2@wgu.edu,21,20,35,40,SOFTWARE"
    };
    const int totalStudents = 5;
    Roster classRoster;

    /*Printing student data*/
    for (int index = 0; index < totalStudents; index++) classRoster.parse(studentData[index]);
        cout << "Student Data: " << endl;
        classRoster.printAll();
        cout << endl;
    
    /*Display invalid emails*/
    cout << "Displaying invalid emails" << endl;
    classRoster.printInvalidEmails();
    cout << endl;

    /*Display days in course average*/
    cout << "Average days in course: " << endl;
    classRoster.printAverageDaysInCourse("A5");
    cout << endl;

    /*Display students who ONLY are in the "Software" degree program*/
    cout << "Ordered by degree program : SOFTWARE" << endl;
    classRoster.printByDegreeProgram(SOFTWARE);
    
    /*Removes student from class roster*/
    cout << "Removing student" << endl;
    classRoster.remove("A3");
    cout << "Student Removed" << endl;

    /*These statements print the roster again and show that "A3" has been successfully removed, respectively*/
    classRoster.printAll();
    classRoster.remove("A3");

    
    return 0;

}

