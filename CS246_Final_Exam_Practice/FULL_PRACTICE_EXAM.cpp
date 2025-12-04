// ============================================================================
// CS246 FINAL EXAM - FULL PRACTICE EXAM
// ============================================================================
// INSTRUCTIONS:
// - This simulates the actual final exam format
// - 30% pre-midterm content, 70% post-midterm content
// - Time yourself: Aim for 2-3 hours
// - Check answer keys in respective ANSWER_KEY.cpp files
// - Total: 174 marks
// ============================================================================

#include <iostream>
#include <vector>
#include <memory>
#include <string>
using namespace std;

// ============================================================================
// PART A: MULTIPLE CHOICE (12 questions × 2 marks = 24 marks)
// ============================================================================

// Q1 [EASY - Pre-Midterm]
// When compiling with separate compilation, which flag creates object files?
// A) -o    B) -c    C) -l    D) -g
// YOUR ANSWER: ___

// Q2 [EASY - Pre-Midterm]
// Which scenario REQUIRES a Member Initialization List (MIL)?
// A) int field  B) const field  C) pointer field  D) double field
// YOUR ANSWER: ___

// Q3 [MEDIUM - Pre-Midterm]
// Which is an R-value?
// A) x (int variable)  B) arr[0]  C) 5 + 3  D) *ptr
// YOUR ANSWER: ___

// Q4 [EASY - Post-Midterm]
// When should a destructor be declared as virtual?
// A) Always  B) Never  C) Only with virtual methods
// D) When used as base class in inheritance hierarchy
// YOUR ANSWER: ___

// Q5 [EASY - Post-Midterm]
// Correct way to catch exceptions polymorphically?
// A) catch (Exception e)  B) catch (Exception* e)
// C) catch (Exception& e)  D) catch (Exception)
// YOUR ANSWER: ___

// Q6 [EASY - Post-Midterm]
// Which smart pointer for ONE owner?
// A) shared_ptr  B) unique_ptr  C) weak_ptr  D) auto_ptr
// YOUR ANSWER: ___

// Q7 [MEDIUM - Post-Midterm]
// What happens if you try to copy a unique_ptr?
// A) Creates new copy  B) Transfers ownership  C) Compilation error  D) Runtime error
// YOUR ANSWER: ___

// Q8 [MEDIUM - Post-Midterm]
// Main advantage of Decorator Pattern over inheritance?
// A) Faster  B) Avoids explosion of subclasses  C) Less memory  D) Easier
// YOUR ANSWER: ___

// Q9 [MEDIUM - Post-Midterm]
// Exception guarantee for swap function with noexcept?
// A) No guarantee  B) Basic  C) Strong  D) No-throw
// YOUR ANSWER: ___

// Q10 [EASY - Post-Midterm]
// Cast for converting double to int?
// A) dynamic_cast  B) static_cast  C) const_cast  D) reinterpret_cast
// YOUR ANSWER: ___

// Q11 [MEDIUM - Post-Midterm]
// What does dynamic_cast return if cast invalid (for pointers)?
// A) Throws exception  B) Returns nullptr  C) Undefined behavior  D) Original pointer
// YOUR ANSWER: ___

// Q12 [EASY - Post-Midterm]
// "Program to interfaces, not implementations" means?
// A) Only use interface classes  B) Depend on abstract base classes
// C) Always use pure virtual  D) Never use inheritance
// YOUR ANSWER: ___


// ============================================================================
// PART B: SHORT ANSWER (20 questions, 3-5 marks each = 80 marks)
// ============================================================================

// ============================================================================
// Q13 [EASY - Pre-Midterm] (3 marks)
// What are the three steps involved in object creation in C++?
//
// Step 1:
// Step 2:
// Step 3:
// ============================================================================


// ============================================================================
// Q14 [MEDIUM - Pre-Midterm] (4 marks)
// Identify and fix all memory leaks:

struct Node_Q14 {
    int data;
    Node_Q14* next;
};

void processNodes_BROKEN() {
    Node_Q14* head = new Node_Q14{1, nullptr};
    Node_Q14* second = new Node_Q14{2, nullptr};
    head->next = second;

    Node_Q14* temp = new Node_Q14{3, nullptr};
    temp = head->next;

    delete head;
}

// LEAKS IDENTIFIED:
// 1.
// 2.

// FIXED VERSION:
void processNodes_FIXED() {
    // YOUR CODE HERE


}
// ============================================================================


// ============================================================================
// Q15 [MEDIUM - Pre-Midterm] (5 marks)
// Implement a copy constructor:

class IntArray_Q15 {
    int* data;
    int size;
public:
    IntArray_Q15(int n) : data{new int[n]}, size{n} {}

    // TODO: Implement copy constructor



    ~IntArray_Q15() { delete[] data; }
};
// ============================================================================


// ============================================================================
// Q16 [MEDIUM - Pre-Midterm] (5 marks)
// Overload << operator for Student class:

class Student_Q16 {
    int id;
    string name;
public:
    Student_Q16(int id, string name) : id{id}, name{name} {}

    // TODO: Add friend declaration

};

// TODO: Implement operator<<


// Expected output: Student[ID: 123, Name: Alice]
// ============================================================================


// ============================================================================
// Q17 [MEDIUM - Post-Midterm] (5 marks)
// Identify memory leak and fix it:

class Base_Q17_BROKEN {
    int* data;
public:
    Base_Q17_BROKEN() : data{new int[10]} {}
    ~Base_Q17_BROKEN() { delete[] data; }
};

class Derived_Q17_BROKEN : public Base_Q17_BROKEN {
    string* name;
public:
    Derived_Q17_BROKEN() : Base_Q17_BROKEN(), name{new string{"Object"}} {}
    ~Derived_Q17_BROKEN() { delete name; }
};

void demonstrateLeak() {
    Base_Q17_BROKEN* ptr = new Derived_Q17_BROKEN();
    delete ptr;  // Memory leak!
}

// EXPLANATION:
//
//

// FIXED VERSION:
class Base_Q17 {
    // YOUR CODE


};

class Derived_Q17 : public Base_Q17 {
    // YOUR CODE


};
// ============================================================================


// ============================================================================
// Q18 [MEDIUM - Post-Midterm] (4 marks)
// Difference between "throw;" vs "throw e;"?
//
// throw; :
//
// throw e; :
//
// Which preserves polymorphic behavior?
// ============================================================================


// ============================================================================
// Q19 [MEDIUM - Post-Midterm] (5 marks)
// Convert to use unique_ptr:

void processData_RAW() {
    int* data = new int[100];
    if (true /* someCondition */) {
        delete[] data;
        return;
    }
    delete[] data;
}

// YOUR VERSION WITH unique_ptr:
void processData_SMART() {



}
// ============================================================================


// ============================================================================
// Q20 [MEDIUM - Post-Midterm] (5 marks)
// Implement Observer Pattern methods:

class Observer_Q20 {
public:
    virtual void notify() = 0;
    virtual ~Observer_Q20() {}
};

class Subject_Q20 {
    vector<Observer_Q20*> observers;
public:
    void attach(Observer_Q20* ob) {
        // YOUR CODE

    }

    void detach(Observer_Q20* ob) {
        // YOUR CODE


    }

    void notifyObservers() {
        // YOUR CODE


    }
};
// ============================================================================


// ============================================================================
// Q21 [MEDIUM - Post-Midterm] (5 marks)
// Complete Template Method Pattern:

class Turtle_Q21 {
public:
    void draw() {  // Template method
        drawHead();
        drawShell();
        drawFeet();
    }
    virtual ~Turtle_Q21() {}
private:
    void drawHead() { cout << "Head" << endl; }
    void drawFeet() { cout << "Feet" << endl; }
    virtual void drawShell() = 0;
};

class RedTurtle : public Turtle_Q21 {
    // YOUR CODE

};

class GreenTurtle : public Turtle_Q21 {
    // YOUR CODE

};
// ============================================================================


// ============================================================================
// Q22 [MEDIUM - Post-Midterm] (4 marks)
// Write template function maximum:

template <typename T>
// YOUR CODE



// What constraint must T satisfy?
//
// ============================================================================


// ============================================================================
// Q23 [MEDIUM - Post-Midterm] (5 marks)
// Safely cast and call derived method:

class Animal_Q23 {
public:
    virtual void speak() { cout << "Animal" << endl; }
    virtual ~Animal_Q23() {}
};

class Dog_Q23 : public Animal_Q23 {
public:
    void speak() override { cout << "Woof!" << endl; }
    void fetch() { cout << "Fetching..." << endl; }
};

void testSafeCasting() {
    Animal_Q23* ptr = new Dog_Q23();

    // TODO: Safely cast ptr to Dog* and call fetch()
    // Handle case where cast might fail




    delete ptr;
}
// ============================================================================


// ============================================================================
// Q24 [EASY - Post-Midterm] (3 marks)
// What is RAII? Provide example.
//
// DEFINITION:
//
//
// EXAMPLE CODE:



// ============================================================================


// ============================================================================
// Q25 [MEDIUM - Post-Midterm] (4 marks)
// Difference between unique_ptr and shared_ptr?
//
// UNIQUE_PTR:
//
//
// SHARED_PTR:
//
//
// WHEN TO USE EACH:
//
// ============================================================================


// ============================================================================
// Q26 [MEDIUM - Post-Midterm] (5 marks)
// What is a pure virtual method? Show example.
//
// DEFINITION:
//
//
// HOW TO DECLARE:
//
//
// EFFECT ON CLASS:
//
//
// EXAMPLE CODE:



// ============================================================================


// ============================================================================
// Q27 [EASY - Post-Midterm] (3 marks)
// What is protected access specifier?
//
// PROTECTED:
//
// VS PRIVATE:
//
// VS PUBLIC:
//
// ============================================================================


// ============================================================================
// Q28 [MEDIUM - Post-Midterm] (5 marks)
// Template function to sum elements using iterators:

template <typename Iter>
int sum(Iter begin, Iter end) {
    // YOUR CODE



}
// ============================================================================


// ============================================================================
// Q29 [MEDIUM - Post-Midterm] (4 marks)
// Complete Factory Pattern:

class Enemy_Q29 {
public:
    virtual void attack() = 0;
    virtual ~Enemy_Q29() {}
};

class Turtle_Q29 : public Enemy_Q29 {
public:
    void attack() override { cout << "Turtle!" << endl; }
};

class Bullet_Q29 : public Enemy_Q29 {
public:
    void attack() override { cout << "Bullet!" << endl; }
};

class Level_Q29 {
public:
    virtual Enemy_Q29* createEnemy() = 0;
    virtual ~Level_Q29() {}
};

class EasyLevel : public Level_Q29 {
    // YOUR CODE - creates mostly turtles


};
// ============================================================================


// ============================================================================
// Q30 [MEDIUM - Post-Midterm] (4 marks)
// Convert to NVI pattern:

class GameCharacter_OLD {
public:
    virtual int healthValue() { return 100; }
};

// YOUR NVI VERSION:
class GameCharacter_NVI {
    // YOUR CODE



};
// ============================================================================


// ============================================================================
// Q31 [EASY - Post-Midterm] (3 marks)
// Write catch blocks in correct order:

class FileException {};
class FileNotFound : public FileException {};
class FilePermissionDenied : public FileException {};

void testExceptions() {
    try {
        // Code that throws
    }
    // YOUR CATCH BLOCKS HERE:




}
// ============================================================================


// ============================================================================
// Q32 [MEDIUM - Pre-Midterm] (4 marks)
// Declaration vs Definition?
//
// DECLARATION:
//
//
// DEFINITION:
//
//
// EXAMPLE DECLARATION:
//
// EXAMPLE DEFINITION:
//
// ============================================================================


// ============================================================================
// PART C: LONG ANSWER (4 questions, 12-15 marks each = 50 marks)
// ============================================================================

// ============================================================================
// Q33 [HARD - Post-Midterm] (15 marks)
// Implement complete Decorator Pattern for coffee shop:
// - Base Coffee class with cost() and description()
// - Espresso: $2.00, "Espresso"
// - Decorators: Milk (+$0.50), Sugar (+$0.25), WhippedCream (+$0.75)

class Coffee_Q33 {
    // YOUR COMPLETE IMPLEMENTATION






};

// Test usage:
// Coffee* order = new WhippedCream{new Milk{new Sugar{new Espresso{}}}};
// Should output: Espresso + Sugar + Milk + Whipped Cream: $3.5
// ============================================================================


// ============================================================================
// Q34 [HARD - Post-Midterm] (12 marks)
// Implement push_back with STRONG exception guarantee:

class MyVector_Q34 {
    int* data;
    int size;
    int capacity;
public:
    MyVector_Q34() : data{nullptr}, size{0}, capacity{0} {}
    ~MyVector_Q34() { delete[] data; }

    void push_back(int value) {
        // YOUR IMPLEMENTATION WITH STRONG GUARANTEE







    }
};

// EXPLANATION OF WHY THIS PROVIDES STRONG GUARANTEE:
//
//
// ============================================================================


// ============================================================================
// Q35 [HARD - Post-Midterm] (13 marks)
// Design abstract Employee hierarchy:
// - Employee: name, employeeID, pure virtual calculatePay() and displayInfo()
// - HourlyEmployee: hourlyRate, hoursWorked (pay = rate × hours)
// - SalaryEmployee: annualSalary (pay = salary / 12)

class Employee_Q35 {
    // YOUR COMPLETE IMPLEMENTATION






};

class HourlyEmployee_Q35 : public Employee_Q35 {
    // YOUR COMPLETE IMPLEMENTATION






};

class SalaryEmployee_Q35 : public Employee_Q35 {
    // YOUR COMPLETE IMPLEMENTATION






};
// ============================================================================


// ============================================================================
// Q36 [HARD - Post-Midterm] (12 marks)
// Implement generic List template with iterator:

template <typename T>
class List_Q36 {
    struct Node {
        T data;
        Node* next;
    };
    Node* head;

public:
    List_Q36() : head{nullptr} {}

    void push_front(T value) {
        // YOUR CODE


    }

    class Iterator {
        Node* curr;
    public:
        Iterator(Node* n) : curr{n} {}

        T& operator*() {
            // YOUR CODE

        }

        Iterator& operator++() {
            // YOUR CODE

        }

        bool operator!=(const Iterator& other) const {
            // YOUR CODE

        }
    };

    Iterator begin() { /* YOUR CODE */ }
    Iterator end() { /* YOUR CODE */ }

    ~List_Q36() {
        // YOUR CODE - delete all nodes



    }
};

// Also write template function to print list:
template <typename T>
void printList(List_Q36<T>& list) {
    // YOUR CODE


}
// ============================================================================


// ============================================================================
// PART D: THEORETICAL QUESTIONS (3 questions, 6-8 marks each = 20 marks)
// ============================================================================

// ============================================================================
// Q37 [MEDIUM - Post-Midterm] (6 marks)
// Explain three exception safety guarantees:
//
// 1. NO-THROW GUARANTEE:
//    Definition:
//    Example scenario:
//    Example code:
//
// 2. STRONG GUARANTEE:
//    Definition:
//    Example scenario:
//    Example code:
//
// 3. BASIC GUARANTEE:
//    Definition:
//    Example scenario:
//    Example code:
// ============================================================================


// ============================================================================
// Q38 [MEDIUM - Post-Midterm] (7 marks)
// Coupling and Cohesion:
//
// a) Define coupling and cohesion (2 marks):
//    COUPLING:
//
//    COHESION:
//
// b) Should each be high or low? Why? (2 marks):
//
//
// c) Code example of tight coupling and how to fix (3 marks):
//    TIGHT COUPLING EXAMPLE:
//
//
//    HOW TO FIX:
//
// ============================================================================


// ============================================================================
// Q39 [MEDIUM - Pre-Midterm] (7 marks)
// L-values, R-values, and Move Semantics:
//
// a) Difference between L-values and R-values (3 marks):
//    L-VALUES:
//    Examples:
//
//    R-VALUES:
//    Examples:
//
// b) Why are move semantics useful? (2 marks):
//
//
// c) When does compiler use move automatically? (2 marks):
//    Scenario 1:
//    Scenario 2:
// ============================================================================


// ============================================================================
// EXAM SUMMARY
// ============================================================================
// Total Marks: 174 marks
//
// Breakdown:
// - Part A (Multiple Choice): 24 marks (14%)
// - Part B (Short Answer): 80 marks (46%)
// - Part C (Long Answer): 50 marks (29%)
// - Part D (Theoretical): 20 marks (11%)
//
// Pre-Midterm: ~30% (Q1-3, Q13-16, Q32, Q39)
// Post-Midterm: ~70% (Q4-12, Q17-31, Q33-38)
//
// Good luck!
// ============================================================================

int main() {
    cout << "CS246 Full Practice Exam" << endl;
    cout << "Complete questions in comments above" << endl;
    cout << "Check ANSWER_KEY.cpp files for solutions" << endl;
    return 0;
}
