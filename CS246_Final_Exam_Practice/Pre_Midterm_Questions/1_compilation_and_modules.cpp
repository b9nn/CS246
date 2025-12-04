// ============================================================================
// CS246 Final Exam Practice - Pre-Midterm
// Topic: Compilation and Modules
// ============================================================================

#include <iostream>
using namespace std;

// ============================================================================
// QUESTION 1 [EASY] - Multiple Choice
// ============================================================================
// When compiling C++ programs with separate compilation, which flag is used
// to compile source files into object files without linking?
//
// A) -o
// B) -c
// C) -l
// D) -g
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// QUESTION 2 [MEDIUM] - Short Answer
// ============================================================================
// Consider the following files:
//
// --- student.h ---
// #ifndef STUDENT_H
// #define STUDENT_H
//
// class Student {
//     int studentID;
//     double gpa;
// public:
//     Student(int id, double gpa);
//     double getGPA();
// };
//
// #endif
//
// --- student.cc ---
// #include "student.h"
//
// Student::Student(int id, double gpa) : studentID{id}, gpa{gpa} {}
//
// double Student::getGPA() { return gpa; }
//
// --- main.cc ---
// #include "student.h"
//
// int main() {
//     Student s{123456, 3.8};
//     return 0;
// }
//
// TASK: Write the complete compilation command(s) needed to produce an
// executable called 'program' from these files.
//
// YOUR ANSWER:
// Command 1:
// Command 2:
// Command 3:
// ============================================================================


// ============================================================================
// QUESTION 3 [MEDIUM] - Theoretical
// ============================================================================
// Explain the difference between a DECLARATION and a DEFINITION in C++.
// Provide an example of each for a function.
//
// DECLARATION:
//
//
// DEFINITION:
//
//
// EXAMPLE FUNCTION DECLARATION:
//
//
// EXAMPLE FUNCTION DEFINITION:
//
//
// ============================================================================


// ============================================================================
// QUESTION 4 [EASY] - Short Answer
// ============================================================================
// Why are header guards (like #ifndef, #define, #endif) necessary in header
// files? What problem do they prevent?
//
// YOUR ANSWER:
//
//
//
//
// ============================================================================
