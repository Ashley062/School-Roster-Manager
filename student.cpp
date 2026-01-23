//
//  student.cpp
//  AshleyWu_c867_project
//
//  Created by Ashley Wu on 1/13/26.
//

#include "student.hpp"
#include "degree.hpp"
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//********** CONSTRUCTORS ********** //
Student::Student()
    : studentID("id"), firstName("fn"), lastName("ln"), emailAddress("email"), age(0), degreeProgram(SOFTWARE) {
    for(int i = 0; i < 3; i++) daysInCourse[i] = 0;
}

Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[3], DegreeProgram degreeProgram)
    : studentID(studentID), firstName(firstName), lastName(lastName), emailAddress(emailAddress), age(age), degreeProgram(degreeProgram)
{
    for(int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}


//********** GETTERS/ACCESSORS ********** //
string Student::GetStudentID() {return studentID;}
string Student::GetFirstName() {return firstName;}
string Student::GetLastName() {return lastName;}
string Student::GetEmailAddress(){return emailAddress;}
int Student::GetAge(){return age;}
int* Student::GetDaysInCourse(){return daysInCourse;}
DegreeProgram Student::GetDegreeProgram(){return degreeProgram;}

//********** SETTERS/MUTATORS ********** //
void Student::SetStudentID(string studentID) { this->studentID = studentID; }
void Student::SetFirstName(string firstName) { this->firstName = firstName; }
void Student::SetLastName(string lastName) { this->lastName = lastName; }
void Student::SetEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::SetAge(int age) { this->age = age; }
void Student::SetDaysInCourse(int daysInCourse[]) {
    for(int i = 0; i < 3; i++) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}
void Student::SetDegreeProgram(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }


//********** OTHERS ********** //
void Student::print() {
    cout << left
         << setw(10) << ("ID: " + studentID)
         << setw(25) << ("Name: " + firstName + " " + lastName)
         << setw(35) << ("Email: " + emailAddress)
         << setw(10) << ("Age: " + to_string(age))
         << "Days in course: {";

    for (int i = 0; i < 3; i++) {
        cout << daysInCourse[i] ;
        if (i < 2) cout << ",";
    } cout << "}";

    cout << setw(5) << " "
        << "Degree Program: "
        << degreeProgram
        << endl;
}
