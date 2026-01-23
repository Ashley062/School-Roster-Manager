//
//  main.cpp
//  AshleyWu_c867_project
//
//  Created by Ashley Wu on 1/13/26.
//
#include <iostream>
#include <string>
#include "roster.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    cout << "C867: Scripting and Programming, C++" << endl;
    cout << "Ashley Wu " << endl;
    cout << "Student ID: 012503251\n" << endl;

    //********** STUDENT DATA ********** //
    const string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Ashley,Wu,ywu20@wgu.edu,27,10,15,20,SOFTWARE"
    };
    
    Roster* classRoster = new Roster();
    
    for (int i = 0; i < 5; i++){
        classRoster->parse(studentData[i]);
    }
    
    classRoster->printAll();
    cout << endl;

    classRoster->printInvalidEmails();
    cout << endl;

    classRoster->printAverageDaysInCourse("A1");
    classRoster->printAverageDaysInCourse("A2");
    classRoster->printAverageDaysInCourse("A3");
    classRoster->printAverageDaysInCourse("A4");
    classRoster->printAverageDaysInCourse("A5");
    cout << endl;

    classRoster->printByDegreeProgram(SOFTWARE);
    cout << endl;

    classRoster->remove("A3");
    cout << endl;

    classRoster->printAll();
    cout << endl;

    classRoster->remove("A3");


    //Destructor
    classRoster->~Roster();
    delete classRoster;
    
    return EXIT_SUCCESS;
}


