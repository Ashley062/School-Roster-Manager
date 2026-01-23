//
//  student.hpp
//  AshleyWu_c867_project
//
//  Created by Ashley Wu on 1/13/26.
//

#ifndef student_hpp
#define student_hpp

#include "degree.hpp"
#include <string>
#include <stdio.h>
using namespace std;

class Student {
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int daysInCourse[3];
    DegreeProgram degreeProgram;
    
public:
    //********** CONSTRUCTORS ********** //
    Student();
    Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[3], DegreeProgram degreeProgram);
    
    //********** GETTERS/ACCESSORS ********** //
    string GetStudentID();
    string GetFirstName();
    string GetLastName();
    string GetEmailAddress();
    int GetAge();
    int* GetDaysInCourse();
    DegreeProgram GetDegreeProgram();

    //********** SETTERS/MUTATORS ********** //
    void SetStudentID(string studentID);
    void SetFirstName(string firstName);
    void SetLastName(string lastName);
    void SetEmailAddress(string emailAddress);
    void SetAge(int age);
    void SetDaysInCourse(int daysInCourse[3]);
    void SetDegreeProgram(DegreeProgram degreeProgram);
    
    //********** OTHERS ********** //
    void print();
};



#endif /* student_hpp */

