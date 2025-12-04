// ============================================================================
// CS246 Final Exam Practice - Pre-Midterm
// Topic: Copying and Moving (The Big 5)
// ============================================================================

#include <iostream>
using namespace std;

// ============================================================================
// QUESTION 1 [EASY] - Multiple Choice
// ============================================================================
// Which of the following is an R-value?
//
// A) x (where x is an int variable)
// B) arr[0] (where arr is an array)
// C) 5 + 3
// D) *ptr (where ptr is a pointer)
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// QUESTION 2 [MEDIUM] - Short Answer
// ============================================================================
// List the BIG 5 special member functions.
// Which are related to copying, and which are related to moving?
//
// COPYING:
// 1.
// 2.
//
// MOVING:
// 3.
// 4.
//
// RESOURCE MANAGEMENT:
// 5.
// ============================================================================


// ============================================================================
// QUESTION 3 [MEDIUM] - Short Answer
// ============================================================================
// Implement a copy constructor for the following class:

class IntArray {
    int* data;
    int size;
public:
    IntArray(int n) : data{new int[n]}, size{n} {}

    // TODO: Implement copy constructor here




    ~IntArray() { delete[] data; }
};

// ============================================================================


// ============================================================================
// QUESTION 4 [HARD] - Short Answer
// ============================================================================
// Implement both the copy assignment operator AND move constructor for the
// IntArray class below:

class IntArray_Full {
    int* data;
    int size;
public:
    IntArray_Full(int n) : data{new int[n]}, size{n} {}

    // TODO: Implement copy assignment operator




    // TODO: Implement move constructor




    ~IntArray_Full() { delete[] data; }
};

// ============================================================================


// ============================================================================
// QUESTION 5 [MEDIUM] - Theoretical
// ============================================================================
// Explain the difference between L-values and R-values.
// Why are move semantics useful, and when does the compiler automatically
// use a move constructor instead of a copy constructor?
//
// L-VALUES:
//
//
// R-VALUES:
//
//
// WHY MOVE SEMANTICS ARE USEFUL:
//
//
// WHEN COMPILER USES MOVE AUTOMATICALLY:
// 1.
// 2.
// 3.
// ============================================================================


// ============================================================================
// QUESTION 6 [EASY] - Short Answer
// ============================================================================
// What happens if you don't define a copy constructor for a class with
// pointer members? What is this behavior called?
//
// YOUR ANSWER:
//
//
// THIS IS CALLED:
// ============================================================================


// ============================================================================
// QUESTION 7 [MEDIUM] - Multiple Choice
// ============================================================================
// Given the code:
//
// IntArray a{10};
// IntArray b{20};
// b = a;
//
// Which function is called on the line "b = a;"?
//
// A) Copy constructor
// B) Move constructor
// C) Copy assignment operator
// D) Move assignment operator
//
// YOUR ANSWER: ___
// ============================================================================
