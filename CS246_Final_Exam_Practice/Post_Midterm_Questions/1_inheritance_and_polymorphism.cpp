// ============================================================================
// CS246 Final Exam Practice - Post-Midterm
// Topic: Inheritance and Polymorphism
// ============================================================================

#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// QUESTION 1 [EASY] - Multiple Choice
// ============================================================================
// What keyword is used to indicate that a derived class method overrides a
// base class method?
//
// A) virtual
// B) override
// C) final
// D) const
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// QUESTION 2 [MEDIUM] - Short Answer
// ============================================================================
// What is wrong with the following code and how would you fix it?

class Book_BROKEN {
public:
    string title;
    Book_BROKEN(string t) : title{t} {}
};

class Comic_BROKEN : public Book_BROKEN {
public:
    string hero;
    Comic_BROKEN(string t, string h) : title{t}, hero{h} {}  // PROBLEM HERE
};

// PROBLEM:
//
//
// FIXED VERSION:
class Book {
public:
    string title;
    Book(string t) : title{t} {}
};

class Comic : public Book {
public:
    string hero;
    // TODO: Fix the constructor


};
// ============================================================================


// ============================================================================
// QUESTION 3 [MEDIUM] - Short Answer
// ============================================================================
// Explain why the following code causes problems (the "array polymorphism
// pitfall"):

class Animal {
    int weight;
public:
    Animal(int w) : weight{w} {}
    int getWeight() { return weight; }
};

class Dog : public Animal {
    string breed;
public:
    Dog(int w, string b) : Animal{w}, breed{b} {}
};

void demonstrateArrayPitfall() {
    Dog dogs[3] = {Dog{10, "Beagle"}, Dog{20, "Poodle"}, Dog{15, "Husky"}};
    Animal* ptr = dogs;
    // ptr[1].getWeight(); // PROBLEM!
}

// EXPLANATION OF PROBLEM:
//
//
//
// HOW TO FIX IT:
//
// ============================================================================


// ============================================================================
// QUESTION 4 [EASY] - Short Answer
// ============================================================================
// What is the 'protected' access specifier?
// How does it differ from 'private' and 'public'?
//
// PROTECTED:
//
//
// VS PRIVATE:
//
// VS PUBLIC:
//
// ============================================================================


// ============================================================================
// QUESTION 5 [MEDIUM] - Theoretical
// ============================================================================
// Explain polymorphism in your own words.
// Provide a real-world example of where polymorphism would be useful.
//
// POLYMORPHISM DEFINITION:
//
//
//
// REAL-WORLD EXAMPLE:
//
//
//
// ============================================================================


// ============================================================================
// QUESTION 6 [HARD] - Long Answer
// ============================================================================
// Design a class hierarchy for a media library system:
// - Base class Media with fields: title, year
// - Derived classes: Book (add author), Movie (add director),
//   Song (add artist, duration)
// - Each class should have appropriate constructors
// - Add a virtual method displayInfo() that each class overrides

class Media {
    // TODO: Your implementation




};

class Book_Media : public Media {
    // TODO: Your implementation




};

class Movie : public Media {
    // TODO: Your implementation




};

class Song : public Media {
    // TODO: Your implementation




};
// ============================================================================
