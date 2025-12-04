/*
obviously you can cast but it leads to bad design as it results in highly coupled code
    - we need to update our fn (comparison via dynamic casting (think book and task)) for all book variants
    - hardcoded checks for multiple types
    - casting is bad design

SOLUTION: VIRTUAL METHODS
*/

#include <iostream>
#include <memory>

class book {
    public:
    virtual void identify() {
        std::cout << "Book";
    }
};

class text : public book {
    public:
    virtual void identify() override {
        std::cout << "text";
    }
};

void whatIsIt(std::unique_ptr<book> b ) {
    if (b) {
        b->identify(); // utilizes the fact that a point uses the method of the actual class
        // not the type at runtime
    }
}

/* what is the heriarchy is not uniform at all? (turtle and bullet both inherit from enemy class but are very different)

each subclass requires an entire overhaul of the enemy baseclass interface

is inheritance the correct method of abstraction? 

if you know enemy will only ever be a turtle or bullet use variants! (you hvae a fixed idea)

variants are like a type safe union of objects, new variatnws still reqruie base class interface changes

if a varitan is left uninitialized, it will be constrcuted with the default ctor of the 1st type

Enemy e; -----> initalizes as a turtle since that it the first listed type

how to init a variante
*/

#include <variant>

using enemy = variant<turtle, bullet>;
using namespace std;

// to init enemy
enemy e{turtle{}} // or bullet{}

if (holds_alternative<turtle> e) {
    cout << "e is a turtle";
}
else {
    cout << "e is a bullet"
}

try {
    // error proine code goes inside the try block
    turtle t = get<Turtle>(e); // e is a turtle if this succeeds
}
catch (std::bad_variant &err) {
    cout << "t is not a turtle!"
}




