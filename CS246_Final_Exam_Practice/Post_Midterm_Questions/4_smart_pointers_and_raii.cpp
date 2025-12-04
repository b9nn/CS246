// ============================================================================
// CS246 Final Exam Practice - Post-Midterm
// Topic: Smart Pointers and RAII
// ============================================================================

#include <iostream>
#include <memory>
#include <string>
using namespace std;

// ============================================================================
// QUESTION 1 [EASY] - Multiple Choice
// ============================================================================
// Which smart pointer should you use when only ONE owner should exist for
// a resource?
//
// A) shared_ptr
// B) unique_ptr
// C) weak_ptr
// D) auto_ptr
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// QUESTION 2 [MEDIUM] - Short Answer
// ============================================================================
// Convert this code to use unique_ptr instead of raw pointers:

void processData_RAW() {
    int* data = new int[100];
    // ... process data ...
    if (true /* someCondition */) {
        delete[] data;
        return;
    }
    // ... more processing ...
    delete[] data;
}

// TODO: Rewrite using unique_ptr
void processData_SMART() {




}
// ============================================================================


// ============================================================================
// QUESTION 3 [MEDIUM] - Multiple Choice
// ============================================================================
// What happens if you try to copy a unique_ptr?
//
// A) It creates a new copy of the resource
// B) It transfers ownership using move semantics
// C) Compilation error - copying is deleted
// D) Runtime error
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// QUESTION 4 [MEDIUM] - Short Answer
// ============================================================================
// Explain the difference between unique_ptr and shared_ptr.
// When would you choose one over the other?
//
// UNIQUE_PTR:
//
//
// SHARED_PTR:
//
//
// WHEN TO USE UNIQUE_PTR:
//
//
// WHEN TO USE SHARED_PTR:
//
// ============================================================================


// ============================================================================
// QUESTION 5 [EASY] - Short Answer
// ============================================================================
// What is RAII (Resource Acquisition Is Initialization)?
// Provide a simple example that demonstrates RAII principles.
//
// DEFINITION:
//
//
// EXAMPLE CODE:




// ============================================================================


// ============================================================================
// QUESTION 6 [HARD] - Long Answer
// ============================================================================
// Implement a simple RAII wrapper class called FileHandle that:
// - Opens a file in the constructor
// - Closes the file in the destructor
// - Provides a method to write to the file
// - Cannot be copied (delete copy operations)
// - Can be moved (implement move operations)

class FileHandle {
    // TODO: Your implementation




};
// ============================================================================


// ============================================================================
// QUESTION 7 [MEDIUM] - Short Answer
// ============================================================================
// Complete this code using shared_ptr:

class Node {
public:
    int data;
    // TODO: What type should next be?


    Node(int d) : data{d} /* TODO: Initialize next */ {}
};

void createLinkedList() {
    // TODO: Create a linked list of 3 nodes using shared_ptr




}
// ============================================================================


// ============================================================================
// QUESTION 8 [MEDIUM] - Short Answer
// ============================================================================
// What method do you call on a smart pointer to get the underlying raw
// pointer? When might you need to do this?
//
// METHOD NAME:
//
// WHEN YOU MIGHT NEED IT:
//
//
// WARNING:
//
// ============================================================================


// ============================================================================
// QUESTION 9 [EASY] - Multiple Choice
// ============================================================================
// How do you create a unique_ptr in modern C++?
//
// A) unique_ptr<int> p = new int{5};
// B) unique_ptr<int> p(new int{5});
// C) auto p = make_unique<int>(5);
// D) Both B and C are correct
//
// YOUR ANSWER: ___
//
// WHICH IS PREFERRED AND WHY?
//
// ============================================================================


// ============================================================================
// QUESTION 10 [HARD] - Theoretical
// ============================================================================
// Explain how shared_ptr implements reference counting.
// What happens when the reference count reaches zero?
// What potential problem can arise with circular references?
//
// REFERENCE COUNTING:
//
//
//
// WHEN COUNT REACHES ZERO:
//
//
// CIRCULAR REFERENCE PROBLEM:
//
//
//
// SOLUTION:
//
// ============================================================================
