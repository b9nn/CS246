// ============================================================================
// CS246 Final Exam Practice - Pre-Midterm
// Topic: Classes and Objects
// ============================================================================

#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// QUESTION 1 [EASY] - Multiple Choice
// ============================================================================
// Which of the following scenarios REQUIRES using a Member Initialization
// List (MIL)?
//
// A) Initializing an int field
// B) Initializing a const field
// C) Initializing a double field
// D) Initializing a pointer field
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// QUESTION 2 [MEDIUM] - Short Answer
// ============================================================================
// Consider this class:

class Book {
    const string author;
    string& title;
    int pages;
public:
    // TASK: Write the constructor implementation using a Member
    // Initialization List
    Book(string a, string& t, int p); // Implementation needed below
};

// YOUR IMPLEMENTATION HERE:




// WHY can't you initialize these fields in the constructor body?
// YOUR ANSWER:
//
//
// ============================================================================


// ============================================================================
// QUESTION 3 [EASY] - Short Answer
// ============================================================================
// What are the three steps involved in object creation in C++?
//
// YOUR ANSWER:
// Step 1:
// Step 2:
// Step 3:
// ============================================================================


// ============================================================================
// QUESTION 4 [MEDIUM] - Theoretical
// ============================================================================
// Explain why making a class field a 'friend' function weakens encapsulation.
// Give an example scenario where using a friend might be justified.
//
// YOUR ANSWER:
//
//
//
// JUSTIFIED SCENARIO:
//
//
// ============================================================================


// ============================================================================
// QUESTION 5 [MEDIUM] - Short Answer
// ============================================================================
// Complete the following class to overload the << operator so that Student
// objects can be printed:

class Student {
    int id;
    string name;
public:
    Student(int id, string name) : id{id}, name{name} {}

    // TODO: Add friend declaration here

};

// TODO: Implement the operator<< function here




// Usage should work like: cout << student << endl;
// Expected output: Student[ID: 123, Name: Alice]
// ============================================================================
