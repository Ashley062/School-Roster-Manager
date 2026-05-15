# C867 - Student Management System

A C++ console application that models a school's student roster system. The program parses student data from a provided dataset, stores it using a class-based structure, and performs data validation, filtering, and reporting.

> **Note:** This is a class project and is not meant to be copied. Feel free to look to see if it helps you understand your code better, but do not copy and paste any of the code.

## About

This project was built to practice core C++ concepts including class design, object-oriented programming, and data manipulation. It was completed as part of the C867: Scripting and Programming Applications course at WGU.

## Features

- Parses raw student data strings into structured `Student` objects
- Stores and manages student records in a `Roster` class
- Identifies and prints invalid email addresses
- Calculates and displays average days in course per student
- Filters students by degree program (Security, Network, or Software)
- Removes students by ID with error handling for missing records
- Prints a full listing of all enrolled students

## Class Structure

### `Student`
Holds individual student data with private attributes and public getters/setters:
- Student ID, first/last name, email address, age
- Days in course (3 courses)
- Degree program

### `Roster`
Manages a collection of `Student` objects with methods to:
- `parse()` — parse a raw data string and add a student
- `add()` — add a student directly
- `remove()` — remove a student by ID
- `printAll()` — display all students
- `printInvalidEmails()` — flag malformed email addresses
- `printAverageDaysInCourse()` — display a student's average course duration
- `printByDegreeProgram()` — filter students by degree

### `DegreeProgram` (enum)
Defines three degree programs: `SECURITY`, `NETWORK`, `SOFTWARE`

## Tech Stack

- **Language**: C++
- **IDE**: Xcode
- **Concepts**: Object-oriented programming, class design, enums, dynamic memory management, string parsing, data validation

## Getting Started

### Compile and run via terminal

```bash
cd project1.0
g++ -o student_system main.cpp student.cpp roster.cpp
./student_system
```

Or open `project1.0.xcodeproj` in Xcode and run the project directly.
