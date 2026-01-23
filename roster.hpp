//
//  roster.hpp
//  AshleyWu_c867_project
//
//  Created by Ashley Wu on 1/13/26.
//


#pragma once
#include "student.hpp"
#include <stdio.h>
using namespace std;

class Roster {
private:
    Student* classRosterArray;
    static int lastIndex;
public:
    Roster();
    ~Roster();
    
    void parse(string row);
    void remove(string studentID);
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    void printAll();
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
};



