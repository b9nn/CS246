// ============================================================================
// CS246 Final Exam Practice - Post-Midterm
// Topic: Virtual Methods and Destructors
// ============================================================================

#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// QUESTION 1 [EASY] - Multiple Choice
// ============================================================================
// When should a destructor be declared as virtual?
//
// A) Always, for all classes
// B) Never, it's not necessary
// C) Only when the class has virtual methods
// D) When the class is used as a base class in an inheritance hierarchy
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// QUESTION 2 [HARD] - Short Answer
// ============================================================================
// Identify the memory leak in this code and explain why it happens.
// Then fix it.

class Base_BROKEN {
    int* data;
public:
    Base_BROKEN() : data{new int[10]} {}
    ~Base_BROKEN() { delete[] data; }
};

class Derived_BROKEN : public Base_BROKEN {
    string* name;
public:
    Derived_BROKEN() : Base_BROKEN(), name{new string{"Object"}} {}
    ~Derived_BROKEN() { delete name; }
};

void demonstrateMemoryLeak() {
    Base_BROKEN* ptr = new Derived_BROKEN();
    delete ptr;  // Memory leak happens here!
}

// EXPLANATION OF MEMORY LEAK:
//
//
//
// FIXED VERSION:
class Base {
    // TODO: Fix this class




};

class Derived : public Base {
    // TODO: Fix this class




};
// ============================================================================


// ============================================================================
// QUESTION 3 [MEDIUM] - Short Answer
// ============================================================================
// What is a PURE VIRTUAL METHOD?
// How do you declare one, and what effect does it have on the class?
//
// DEFINITION:
//
//
// HOW TO DECLARE:
//
//
// EFFECT ON CLASS:
//
// ============================================================================


// ============================================================================
// QUESTION 4 [MEDIUM] - Theoretical
// ============================================================================
// Explain the concept of RUNTIME METHOD DISPATCH (dynamic dispatch).
// How does the compiler determine which method to call when you invoke a
// virtual method through a base class pointer?
//
// YOUR ANSWER:
//
//
//
//
// ============================================================================


// ============================================================================
// QUESTION 5 [MEDIUM] - Short Answer
// ============================================================================
// Complete the Circle class by implementing the required pure virtual methods:

class Shape {
public:
    virtual void draw() = 0;
    virtual double area() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius{r} {}

    // TODO: Implement draw() method


    // TODO: Implement area() method (use formula πr²)


};
// ============================================================================


// ============================================================================
// QUESTION 6 [EASY] - Multiple Choice
// ============================================================================
// What is the order of destructor execution in an inheritance hierarchy?
//
// A) Base class destructor → Derived class destructor
// B) Derived class destructor body → Derived class fields → Base class dtor
// C) Base class fields → Base dtor → Derived fields → Derived dtor
// D) All destructors execute simultaneously
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// QUESTION 7 [HARD] - Long Answer
// ============================================================================
// Design an abstract Employee class hierarchy:
// - Abstract base class Employee with pure virtual calculatePay() and
//   displayInfo()
// - Common fields: name, employeeID
// - Derived HourlyEmployee: add hourlyRate, hoursWorked
// - Derived SalaryEmployee: add annualSalary
// - Include virtual destructors and proper constructors

class Employee {
    // TODO: Your implementation




};

class HourlyEmployee : public Employee {
    // TODO: Your implementation




};

class SalaryEmployee : public Employee {
    // TODO: Your implementation




};
// ============================================================================
