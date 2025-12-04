// ============================================================================
// CS246 Final Exam Practice - Post-Midterm
// Topic: Design Patterns (ALL 6 PATTERNS)
// ============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// ============================================================================
// FACTORY PATTERN
// ============================================================================

// ============================================================================
// QUESTION 1 [MEDIUM] - Factory Pattern
// ============================================================================
// Complete the Factory Pattern implementation for creating different types
// of enemies in a game:

class Enemy {
public:
    virtual void attack() = 0;
    virtual ~Enemy() {}
};

class Turtle : public Enemy {
public:
    void attack() override { cout << "Turtle attack!" << endl; }
};

class Bullet : public Enemy {
public:
    void attack() override { cout << "Bullet attack!" << endl; }
};

class Level {
public:
    virtual Enemy* createEnemy() = 0;
    virtual ~Level() {}
};

// TODO: Complete the EasyLevel class (creates mostly turtles)
class EasyLevel : public Level {



};

// TODO: Complete the HardLevel class (creates mostly bullets)
class HardLevel : public Level {



};
// ============================================================================


// ============================================================================
// QUESTION 2 [MEDIUM] - Theoretical
// ============================================================================
// Explain the purpose of the Factory Pattern.
// What problem does it solve, and when would you use it?
//
// PURPOSE:
//
//
// PROBLEM IT SOLVES:
//
//
// WHEN TO USE:
//
// ============================================================================


// ============================================================================
// DECORATOR PATTERN
// ============================================================================

// ============================================================================
// QUESTION 3 [HARD] - Decorator Pattern
// ============================================================================
// Implement the complete Decorator Pattern for a coffee shop ordering system:
// - Base Coffee class with cost() and description() methods
// - Concrete coffee: Espresso (base cost $2.00)
// - Decorators: Milk (+$0.50), Sugar (+$0.25), WhippedCream (+$0.75)
// - Each decorator wraps a Coffee and adds to its cost/description

class Coffee {
public:
    // TODO: Your implementation




};

class Espresso : public Coffee {
public:
    // TODO: Your implementation


};

class CoffeeDecorator : public Coffee {
protected:
    // TODO: Your implementation


};

class Milk : public CoffeeDecorator {
public:
    // TODO: Your implementation



};

class Sugar : public CoffeeDecorator {
public:
    // TODO: Your implementation



};

class WhippedCream : public CoffeeDecorator {
public:
    // TODO: Your implementation



};

// Usage example:
// Coffee* order = new WhippedCream{new Milk{new Sugar{new Espresso{}}}};
// cout << order->description() << ": $" << order->cost() << endl;
// Output: Espresso + Sugar + Milk + Whipped Cream: $3.5
// ============================================================================


// ============================================================================
// QUESTION 4 [EASY] - Multiple Choice
// ============================================================================
// What is the main advantage of the Decorator Pattern over using inheritance?
//
// A) It's faster to execute
// B) It avoids an explosion of subclass combinations
// C) It uses less memory
// D) It's easier to understand
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// OBSERVER PATTERN
// ============================================================================

// ============================================================================
// QUESTION 5 [MEDIUM] - Observer Pattern
// ============================================================================
// Implement the attach and notifyObservers methods for the Observer Pattern:

class Observer {
public:
    virtual void notify() = 0;
    virtual ~Observer() {}
};

class Subject {
    vector<Observer*> observers;
public:
    void attach(Observer* ob) {
        // TODO: Your implementation

    }

    void detach(Observer* ob) {
        // TODO: Your implementation


    }

    void notifyObservers() {
        // TODO: Your implementation


    }
};
// ============================================================================


// ============================================================================
// QUESTION 6 [MEDIUM] - Observer Pattern
// ============================================================================
// Create a concrete Observer and Subject for a temperature monitoring system:
// - TemperatureSensor (Subject) has a temperature value
// - Display (Observer) prints the temperature when notified
// - Alarm (Observer) sounds if temperature exceeds threshold

class TemperatureSensor : public Subject {
    // TODO: Your implementation




};

class Display : public Observer {
    // TODO: Your implementation




};

class Alarm : public Observer {
    // TODO: Your implementation




};
// ============================================================================


// ============================================================================
// TEMPLATE METHOD PATTERN
// ============================================================================

// ============================================================================
// QUESTION 7 [MEDIUM] - Template Method Pattern
// ============================================================================
// Complete the Template Method Pattern for drawing different types of turtles:

class Turtle_Template {
public:
    void draw() {  // Template method
        drawHead();
        drawShell();
        drawFeet();
    }

    virtual ~Turtle_Template() {}

private:
    void drawHead() { cout << "Drawing head" << endl; }
    void drawFeet() { cout << "Drawing feet" << endl; }

    virtual void drawShell() = 0;  // Customizable step
};

// TODO: Complete these classes
class RedTurtle : public Turtle_Template {



};

class GreenTurtle : public Turtle_Template {



};
// ============================================================================


// ============================================================================
// QUESTION 8 [EASY] - Theoretical
// ============================================================================
// In the Template Method Pattern, which part stays in the superclass and
// which part is customized by subclasses?
//
// SUPERCLASS:
//
//
// SUBCLASSES:
//
//
// ============================================================================


// ============================================================================
// NVI (NON-VIRTUAL INTERFACE) PATTERN
// ============================================================================

// ============================================================================
// QUESTION 9 [MEDIUM] - NVI Pattern
// ============================================================================
// Convert this class to use the NVI pattern:

class GameCharacter_OLD {
public:
    virtual int healthValue() {
        // calculate health
        return 100;
    }
};

// TODO: Rewrite using NVI pattern (public non-virtual, private virtual)
class GameCharacter {



};
// ============================================================================


// ============================================================================
// QUESTION 10 [MEDIUM] - Theoretical
// ============================================================================
// What is the main benefit of the NVI pattern?
// How does it allow better control over the interface?
//
// MAIN BENEFIT:
//
//
// CONTROL IT PROVIDES:
//
//
// ============================================================================


// ============================================================================
// ABSTRACT ITERATOR PATTERN
// ============================================================================

// ============================================================================
// QUESTION 11 [HARD] - Abstract Iterator Pattern
// ============================================================================
// Implement an abstract iterator for a custom list:

class AbstractIterator {
public:
    virtual int& operator*() = 0;
    virtual AbstractIterator& operator++() = 0;
    virtual bool operator!=(const AbstractIterator& other) = 0;
    virtual ~AbstractIterator() {}
};

class List {
    struct Node {
        int data;
        Node* next;
    };
    Node* head;

public:
    List() : head{nullptr} {}

    class Iterator : public AbstractIterator {
        Node* curr;
    public:
        Iterator(Node* n) : curr{n} {}

        // TODO: Implement all pure virtual methods




    };

    Iterator begin() { /* TODO */ }
    Iterator end() { /* TODO */ }
};
// ============================================================================


// ============================================================================
// QUESTION 12 [MEDIUM] - Abstract Iterator
// ============================================================================
// Write a template function foreach that uses an abstract iterator:

template <typename Iter, typename Func>
void foreach(Iter begin, Iter end, Func f) {
    // TODO: Your implementation - call f on each element



}
// ============================================================================


// ============================================================================
// DESIGN PRINCIPLES
// ============================================================================

// ============================================================================
// QUESTION 13 [EASY] - Multiple Choice
// ============================================================================
// What does "program to interfaces, not implementations" mean?
//
// A) Only use interface classes, never concrete classes
// B) Depend on abstract base classes rather than concrete derived classes
// C) Always use pure virtual methods
// D) Never use inheritance
//
// YOUR ANSWER: ___
// ============================================================================


// ============================================================================
// QUESTION 14 [MEDIUM] - Theoretical
// ============================================================================
// Explain the concepts of COUPLING and COHESION.
// Which should be high and which should be low? Why?
//
// COUPLING:
//
//
// COHESION:
//
//
// HIGH OR LOW?
//
//
// WHY?
//
// ============================================================================


// ============================================================================
// QUESTION 15 [MEDIUM] - Short Answer
// ============================================================================
// Identify whether the following code demonstrates high or low coupling.
// How would you improve it?

class Engine {
public:
    void start() { cout << "Engine starting" << endl; }
};

class Car_TIGHT {
    Engine engine;  // Car directly creates Engine
public:
    Car_TIGHT() : engine{} {}
    void drive() {
        engine.start();
    }
};

// COUPLING LEVEL:
//
// HOW TO IMPROVE (show code):




// ============================================================================
