// ============================================================================
// CS246 Final Exam Practice - Pre-Midterm
// Topic: Memory Management
// ============================================================================

#include <iostream>
using namespace std;

// ============================================================================
// QUESTION 1 [EASY] - Multiple Choice
// ============================================================================
// Which of the following allocates memory on the heap?
//
// A) int x = 5;
// B) int* p = new int{5};
// C) int arr[10];
// D) Creating a local variable in a function
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// QUESTION 2 [MEDIUM] - Short Answer
// ============================================================================
// Identify and fix all memory leaks in the following code:

struct Node {
    int data;
    Node* next;
};

void processNodes_BROKEN() {
    Node* head = new Node{1, nullptr};
    Node* second = new Node{2, nullptr};
    head->next = second;

    Node* temp = new Node{3, nullptr};
    temp = head->next;

    delete head;
}

// TASK: Rewrite the function below to fix all memory leaks
void processNodes_FIXED() {
    // YOUR CODE HERE:




}

// EXPLANATION OF LEAKS:
// 1.
// 2.
// ============================================================================


// ============================================================================
// QUESTION 3 [MEDIUM] - Short Answer
// ============================================================================
// What is the difference between stack memory and heap memory?
// Give two advantages and one disadvantage of each.
//
// STACK MEMORY:
// Advantages:
// 1.
// 2.
// Disadvantage:
// 1.
//
// HEAP MEMORY:
// Advantages:
// 1.
// 2.
// Disadvantage:
// 1.
// ============================================================================


// ============================================================================
// QUESTION 4 [HARD] - Short Answer
// ============================================================================
// What is wrong with this code? How would you fix it?

int* createArray_BROKEN() {
    int arr[5] = {1, 2, 3, 4, 5};
    return arr;
}

void testBrokenArray() {
    int* p = createArray_BROKEN();
    cout << p[0] << endl;
}

// PROBLEM:
//
//
// FIXED VERSION:
int* createArray_FIXED() {
    // YOUR CODE HERE:


}
// ============================================================================


// ============================================================================
// QUESTION 5 [EASY] - Short Answer
// ============================================================================
// What happens when you dereference a nullptr?
// Why is it important to initialize pointers?
//
// YOUR ANSWER:
//
//
//
// ============================================================================
