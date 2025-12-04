// ============================================================================
// CS246 Final Exam Practice - Pre-Midterm
// Topic: Operator Overloading
// ============================================================================

#include <iostream>
using namespace std;

// ============================================================================
// QUESTION 1 [EASY] - Short Answer
// ============================================================================
// Why is the operator<< typically implemented as a NON-MEMBER FRIEND function
// rather than a member function?
//
// YOUR ANSWER:
//
//
//
// ============================================================================


// ============================================================================
// QUESTION 2 [MEDIUM] - Short Answer
// ============================================================================
// Implement the + operator for the following Vector2D class so that two
// vectors can be added together:

class Vector2D {
    double x, y;
public:
    Vector2D(double x, double y) : x{x}, y{y} {}

    double getX() const { return x; }
    double getY() const { return y; }

    // TODO: Implement operator+ here (as a member function)




};

// Usage: Vector2D v3 = v1 + v2;
// ============================================================================


// ============================================================================
// QUESTION 3 [MEDIUM] - Short Answer
// ============================================================================
// Implement the >> (input) operator for a Point class:

class Point {
    int x, y;
public:
    Point() : x{0}, y{0} {}

    // TODO: Add friend declaration


};

// TODO: Implement operator>> here
// It should read two integers from the input stream and store them in x and y




// ============================================================================


// ============================================================================
// QUESTION 4 [EASY] - Multiple Choice
// ============================================================================
// When overloading the = (assignment) operator, what should it return?
//
// A) void
// B) A copy of the object
// C) A reference to *this
// D) A const reference to the object
//
// YOUR ANSWER: ___
//
// WHY?
//
// ============================================================================
