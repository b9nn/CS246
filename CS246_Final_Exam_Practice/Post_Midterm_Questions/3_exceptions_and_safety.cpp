// ============================================================================
// CS246 Final Exam Practice - Post-Midterm
// Topic: Exceptions and Exception Safety
// ============================================================================

#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

// ============================================================================
// QUESTION 1 [EASY] - Multiple Choice
// ============================================================================
// What is the correct way to catch exceptions polymorphically?
//
// A) catch (Exception e)
// B) catch (Exception* e)
// C) catch (Exception& e)
// D) catch (Exception)
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// QUESTION 2 [MEDIUM] - Short Answer
// ============================================================================
// What is the difference between using "throw;" (bare throw) versus
// "throw e;" when re-throwing an exception?
// Which one preserves polymorphic behavior?
//
// YOUR ANSWER:
//
//
//
//
// ============================================================================


// ============================================================================
// QUESTION 3 [MEDIUM] - Short Answer
// ============================================================================
// Complete this code that demonstrates exception unwinding:

void funcC() {
    // TODO: Throw an exception here

}

void funcB() {
    // TODO: Call funcC

}

void funcA() {
    // TODO: Call funcB with try-catch



}

// EXPLANATION OF WHAT HAPPENS DURING UNWINDING:
//
//
//
// ============================================================================


// ============================================================================
// QUESTION 4 [HARD] - Theoretical
// ============================================================================
// Explain the three levels of exception safety guarantees:
//
// 1. NO-THROW GUARANTEE:
//    Definition:
//    Example scenario:
//
//
// 2. STRONG GUARANTEE:
//    Definition:
//    Example scenario:
//
//
// 3. BASIC GUARANTEE:
//    Definition:
//    Example scenario:
//
// ============================================================================


// ============================================================================
// QUESTION 5 [MEDIUM] - Multiple Choice
// ============================================================================
// Which exception guarantee does the following function provide?
//
// void swap(int& a, int& b) noexcept {
//     int temp = a;
//     a = b;
//     b = temp;
// }
//
// A) No guarantee
// B) Basic guarantee
// C) Strong guarantee
// D) No-throw guarantee
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// QUESTION 6 [HARD] - Long Answer
// ============================================================================
// Implement a push_back method for a vector class that provides the
// STRONG EXCEPTION GUARANTEE using the copy-and-swap idiom:

class MyVector {
    int* data;
    int size;
    int capacity;
public:
    MyVector() : data{nullptr}, size{0}, capacity{0} {}

    ~MyVector() { delete[] data; }

    // TODO: Implement push_back with strong exception guarantee
    void push_back(int value) {







    }
};

// EXPLANATION OF WHY THIS PROVIDES STRONG GUARANTEE:
//
//
// ============================================================================


// ============================================================================
// QUESTION 7 [MEDIUM] - Short Answer
// ============================================================================
// What is the PIMPL idiom (Pointer to Implementation)?
// How does it help achieve exception safety?
//
// YOUR ANSWER:
//
//
//
// OTHER BENEFITS:
//
// ============================================================================


// ============================================================================
// QUESTION 8 [EASY] - Short Answer
// ============================================================================
// What happens to local objects when an exception is thrown?
// Why is RAII important for exception safety?
//
// YOUR ANSWER:
//
//
//
// ============================================================================


// ============================================================================
// QUESTION 9 [MEDIUM] - Short Answer
// ============================================================================
// Write a try-catch block that handles this exception hierarchy correctly:

class FileException {};
class FileNotFound : public FileException {};
class FilePermissionDenied : public FileException {};

void testExceptionHandling() {
    try {
        // Code that may throw
    }
    // TODO: Add catch blocks in correct order
    // 1. Catch FileNotFound and print "File not found"
    // 2. Catch FilePermissionDenied and print "Permission denied"
    // 3. Catch any other FileException and print "File error"




}
// ============================================================================
