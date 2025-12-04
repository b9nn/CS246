// ============================================================================
// CS246 Final Exam Practice - Post-Midterm
// Topic: Casting (static_cast, dynamic_cast, const_cast, reinterpret_cast)
// ============================================================================

#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// QUESTION 1 [EASY] - Multiple Choice
// ============================================================================
// Which cast should you use for converting a double to an int?
//
// A) dynamic_cast
// B) static_cast
// C) const_cast
// D) reinterpret_cast
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// QUESTION 2 [MEDIUM] - Short Answer
// ============================================================================
// What is the difference between static_cast and dynamic_cast?
// When would you use each?
//
// STATIC_CAST:
//
//
// DYNAMIC_CAST:
//
//
// WHEN TO USE STATIC_CAST:
//
//
// WHEN TO USE DYNAMIC_CAST:
//
// ============================================================================


// ============================================================================
// QUESTION 3 [MEDIUM] - Short Answer
// ============================================================================
// Complete this code to safely cast and call a derived-specific method:

class Animal {
public:
    virtual void speak() { cout << "Animal sound" << endl; }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() override { cout << "Woof!" << endl; }
    void fetch() { cout << "Fetching..." << endl; }
};

void testCasting() {
    Animal* ptr = new Dog();

    // TODO: Safely cast ptr to Dog* to call fetch()
    // Handle the case where the cast might fail




    delete ptr;
}
// ============================================================================


// ============================================================================
// QUESTION 4 [EASY] - Multiple Choice
// ============================================================================
// What does dynamic_cast return if the cast is invalid (for pointers)?
//
// A) Throws an exception
// B) Returns nullptr
// C) Causes undefined behavior
// D) Returns the original pointer unchanged
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// QUESTION 5 [MEDIUM] - Short Answer
// ============================================================================
// What is required for dynamic_cast to work? Why does this requirement exist?
//
// REQUIREMENTS:
//
//
// WHY THIS REQUIREMENT:
//
// ============================================================================


// ============================================================================
// QUESTION 6 [MEDIUM] - Short Answer
// ============================================================================
// Explain what const_cast does and provide a scenario where it might be used
// (even though it's generally discouraged):

void exampleFunction(const int& x) {
    // Suppose we need to modify x for some legacy reason
    // TODO: Show how const_cast would be used here


}

// WHAT CONST_CAST DOES:
//
//
// SCENARIO FOR USE:
//
//
// WARNING:
//
// ============================================================================


// ============================================================================
// QUESTION 7 [HARD] - Short Answer
// ============================================================================
// For each scenario, identify which cast to use and why:
//
// a) Converting float to int
//    CAST:              WHY:
//
//
// b) Downcasting in a polymorphic hierarchy with runtime type checking
//    CAST:              WHY:
//
//
// c) Removing const from a const reference
//    CAST:              WHY:
//
//
// d) Converting between unrelated pointer types (e.g., int* to char*)
//    CAST:              WHY:
//
// ============================================================================


// ============================================================================
// QUESTION 8 [MEDIUM] - Multiple Choice
// ============================================================================
// What is the main advantage of C++-style casts over C-style casts?
//
// A) They are shorter to write
// B) They are more explicit about intent and safer
// C) They are faster at runtime
// D) They can cast between any types
//
// YOUR ANSWER: ___
//
// EXPLANATION:
//
// ============================================================================
