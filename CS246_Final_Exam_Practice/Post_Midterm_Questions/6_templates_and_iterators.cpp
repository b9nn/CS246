// ============================================================================
// CS246 Final Exam Practice - Post-Midterm
// Topic: Templates and Iterators (MARKED ONFINAL)
// ============================================================================

#include <iostream>
#include <vector>
using namespace std;

// ============================================================================
// QUESTION 1 [EASY] - Short Answer
// ============================================================================
// Write a template function 'maximum' that returns the larger of two values:

template <typename T>
// TODO: Your implementation




// Usage: maximum(5, 10) should return 10
//        maximum(3.5, 2.1) should return 3.5
// ============================================================================


// ============================================================================
// QUESTION 2 [MEDIUM] - Short Answer
// ============================================================================
// What constraint must type T satisfy in this template function?

template <typename T>
T findMin(T a, T b, T c) {
    T min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}

// CONSTRAINT:
//
// ============================================================================


// ============================================================================
// QUESTION 3 [MEDIUM] - Short Answer
// ============================================================================
// Implement a template function 'printArray' that prints all elements:

template <typename T>
void printArray(T arr[], int size) {
    // TODO: Your implementation



}
// ============================================================================


// ============================================================================
// QUESTION 4 [HARD] - Long Answer
// ============================================================================
// Implement a generic List class template that stores any type:

template <typename T>
class List {
    struct Node {
        T data;
        Node* next;
    };
    Node* head;

public:
    List() : head{nullptr} {}

    void push_front(T value) {
        // TODO: Your implementation


    }

    class Iterator {
        Node* curr;
    public:
        Iterator(Node* n) : curr{n} {}

        T& operator*() {
            // TODO: Your implementation

        }

        Iterator& operator++() {
            // TODO: Your implementation

        }

        bool operator!=(const Iterator& other) const {
            // TODO: Your implementation

        }
    };

    Iterator begin() { /* TODO */ }
    Iterator end() { /* TODO */ }

    ~List() {
        // TODO: Delete all nodes



    }
};
// ============================================================================


// ============================================================================
// QUESTION 5 [MEDIUM] - Short Answer
// ============================================================================
// Write a template function that uses iterators to sum all elements:

template <typename Iter>
int sum(Iter begin, Iter end) {
    // TODO: Your implementation



}
// ============================================================================


// ============================================================================
// QUESTION 6 [MEDIUM] - Multiple Choice
// ============================================================================
// What is TYPE INFERENCE in templates?
//
// A) The compiler guesses the type at runtime
// B) The compiler deduces template type parameters from function arguments
// C) The programmer must always specify types explicitly
// D) Types are converted automatically
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// QUESTION 7 [HARD] - Short Answer
// ============================================================================
// Implement a variadic template function that prints any number of arguments:

// Base case
void print() {}

// Recursive case
template <typename T, typename... Args>
void print(T first, Args... rest) {
    // TODO: Your implementation - print first, then recursively print rest



}

// Usage: print(1, "hello", 3.14, 'c') should print all four values
// ============================================================================


// ============================================================================
// QUESTION 8 [MEDIUM] - Short Answer
// ============================================================================
// What would happen if you try to call maximum(5, 3.14) with this template?

// template <typename T>
// T maximum(T a, T b) {
//     return (a > b) ? a : b;
// }

// PROBLEM:
//
//
// HOW TO FIX:
//
// ============================================================================


// ============================================================================
// QUESTION 9 [EASY] - Theoretical
// ============================================================================
// Explain why templates are a form of GENERIC PROGRAMMING.
// What benefit do they provide over writing separate functions for each type?
//
// GENERIC PROGRAMMING:
//
//
// BENEFITS:
//
//
// ============================================================================


// ============================================================================
// QUESTION 10 [MEDIUM] - Short Answer
// ============================================================================
// Write a template function 'contains' that checks if a value exists in a
// container using iterators:

template <typename Iter, typename T>
bool contains(Iter begin, Iter end, T value) {
    // TODO: Your implementation




}
// ============================================================================
