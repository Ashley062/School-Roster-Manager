//
//  roster.cpp
//  AshleyWu_c867_project
//
//  Created by Ashley Wu on 1/13/26.
//


#include "roster.hpp"
#include <iostream>
#include <string>
using namespace std;


Roster::Roster(){
    classRosterArray = new Student[5];
}
Roster::~Roster(){
    delete[] classRosterArray;
}
int Roster::lastIndex = 0;


void Roster::parse(string row){
    
    size_t pos;
    string studentID, firstName, lastName, emailAddress, degreeProgram;
    int studentAge, daysInCourse1, daysInCourse2, daysInCourse3;
    
    pos = row.find(",");
    studentID = row.substr(0, pos);
    row.erase(0, pos + 1);
    
    pos = row.find(",");
    firstName = row.substr(0, pos);
    row.erase(0, pos + 1);
    
    pos = row.find(",");
    lastName = row.substr(0, pos);
    row.erase(0, pos + 1);
    
    pos = row.find(",");
    emailAddress = row.substr(0, pos);
    row.erase(0, pos + 1);
    
    pos = row.find(",");
    studentAge = stoi(row.substr(0, pos));
    row.erase(0, pos + 1);
    
    pos = row.find(",");
    daysInCourse1 = stoi(row.substr(0, pos));
    row.erase(0, pos + 1);
    
    pos = row.find(",");
    daysInCourse2 = stoi(row.substr(0, pos));
    row.erase(0, pos + 1);
    
    pos = row.find(",");
    daysInCourse3 = stoi(row.substr(0, pos));
    row.erase(0, pos + 1);
     
    degreeProgram = row;
    
    DegreeProgram dp;
    if(degreeProgram == "SECURITY") {
        dp = SECURITY;
    }
    else if(degreeProgram == "NETWORK") {
        dp = NETWORK;
    }
    else {
        dp = SOFTWARE;
    }
    
    add(studentID, firstName, lastName, emailAddress, studentAge,
        daysInCourse1, daysInCourse2, daysInCourse3, dp);
}


void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram){
    
    int daysArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    classRosterArray[lastIndex] = Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);
    
    lastIndex++;
    

}

void Roster::printAll(){
    cout << "********** STUDENT DATA **********" << endl;
    for (int i = 0; i < lastIndex; i++) {
        classRosterArray[i].print();
    }
    cout << "\n";
}

void Roster::printInvalidEmails(){
    for (int i = 0; i < lastIndex; i++) {
        string email = classRosterArray[i].GetEmailAddress();
        
        if (email.find("@") == string::npos || email.find(" ") != string::npos || email.find(".") == string::npos) {
            cout << "Invalid email: " << email << endl;
        }
        
    }
}


void Roster::remove(string studentID){
    bool studentFound = false;
    
    for (int i = 0; i < lastIndex; i++) {
           if (classRosterArray[i].GetStudentID() == studentID) {
               studentFound = true;
   
               // shift elements left
               for (int j = i; j < lastIndex - 1; j++) {
                   classRosterArray[j] = classRosterArray[j + 1];
               }
   
               lastIndex--;
               break;
           }
       }
    
    if (!studentFound) {
        cout << "Student with ID: " << studentID << " is not found.\n" << endl;
    } else {
        cout << "Student with ID: " << studentID << " is deleted.\n" << endl;
    }
        
    
}


void Roster::printAverageDaysInCourse(string studentID) {
    bool found = false;

    for (int i = 0; i < lastIndex; i++) {
        if (studentID == classRosterArray[i].GetStudentID()) {
            int* days = classRosterArray[i].GetDaysInCourse();

            double avg = (days[0] + days[1] + days[2]) / 3.0;

            cout << "Average days in course for "
                 << studentID << ": " << avg << endl;

            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student with ID " << studentID << " not found." << endl;
    }
}



void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    string degreeString;
    if (degreeProgram == SECURITY) {
        degreeString = "SECURITY";
    } else if ( degreeProgram == NETWORK) {
        degreeString = "NETWORK";
    } else {
        degreeString = "SOFTWARE";
    }
    cout << "Students with degree program: " << degreeString << endl;
    for(int i = 0; i < lastIndex; i++){
            if(classRosterArray[i].GetDegreeProgram() == degreeProgram) {
                classRosterArray[i].print();
            }
        }
}
