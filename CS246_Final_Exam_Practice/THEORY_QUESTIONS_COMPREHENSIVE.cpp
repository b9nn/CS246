// ============================================================================
// CS246 COMPREHENSIVE THEORY QUESTIONS
// Advanced C++ OOP Concepts: Inheritance, Polymorphism, Virtual Methods
// Format: Multiple Choice and True/False
// Total: 40 Questions (Mixed Difficulty: Easy → Extremely Hard)
// ============================================================================
//
// Answer each question by selecting the correct option or True/False.
// Check THEORY_ANSWERS.cpp for complete explanations.
//
// ============================================================================

#include <iostream>
#include <memory>
#include <string>
using namespace std;

// ============================================================================
// SECTION 1: OBJECT SLICING (Questions 1-5)
// ============================================================================

// Q1 [EASY] - TRUE/FALSE
// Object slicing occurs when a derived class object is assigned to a base
// class pointer.
//
// YOUR ANSWER: _____

// Q2 [MEDIUM] - Multiple Choice
// Consider the following code:
/*
class Book {
    int length;
public:
    Book(int l) : length{l} {}
};

class Comic : public Book {
    string hero;
public:
    Comic(int l, string h) : Book{l}, hero{h} {}
};

int main() {
    Comic c{50, "Flash"};
    Book b = c;        // Line A
    Book* bp = &c;     // Line B
    Book& br = c;      // Line C
}
*/
// On which line(s) does object slicing occur?
//
// A) Line A only
// B) Line B only
// C) Line C only
// D) Lines A and B
// E) All three lines
//
// YOUR ANSWER: _____

// Q3 [MEDIUM] - TRUE/FALSE
// When object slicing occurs, the derived class fields are lost but virtual
// method dispatch still works correctly on the sliced object.
//
// YOUR ANSWER: _____

// Q4 [HARD] - Multiple Choice
// Given this code:
/*
class Base {
    int x;
public:
    Base(int x) : x{x} {}
    Base(const Base& other) : x{other.x} { cout << "Base copy" << endl; }
};

class Derived : public Base {
    int y;
public:
    Derived(int x, int y) : Base{x}, y{y} {}
    Derived(const Derived& other) : Base{other}, y{other.y} {
        cout << "Derived copy" << endl;
    }
};

int main() {
    Derived d{1, 2};
    Base b = d;
}
*/
// What is printed?
//
// A) "Base copy" only
// B) "Derived copy" only
// C) "Base copy" followed by "Derived copy"
// D) "Derived copy" followed by "Base copy"
// E) Nothing is printed
//
// YOUR ANSWER: _____

// Q5 [EXTREMELY HARD] - Multiple Choice
// Consider this code:
/*
class A { int x; public: A(int x) : x{x} {} };
class B : public A { int y; public: B(int x, int y) : A{x}, y{y} {} };

void foo(A a) { }

int main() {
    B b{1, 2};
    A* ap = &b;
    foo(*ap);
}
*/
// What happens when foo(*ap) is called?
//
// A) Compiler error: cannot pass base reference where derived expected
// B) Object slicing occurs when passing to foo, only A's fields are copied
// C) No slicing occurs because ap is a pointer
// D) Runtime error due to type mismatch
// E) Undefined behavior
//
// YOUR ANSWER: _____


// ============================================================================
// SECTION 2: VIRTUAL VS NON-VIRTUAL METHODS (Questions 6-12)
// ============================================================================

// Q6 [EASY] - TRUE/FALSE
// If a method is not declared virtual in the base class, it can still be
// overridden in the derived class, but polymorphism won't work.
//
// YOUR ANSWER: _____

// Q7 [MEDIUM] - Multiple Choice
/*
class Book {
    int len;
public:
    Book(int l) : len{l} {}
    bool isHeavy() { return len > 200; }
};

class Comic : public Book {
public:
    Comic(int l) : Book{l} {}
    bool isHeavy() { return len > 30; }  // Note: len is private in Book!
};

int main() {
    Comic c{50};
    Book* bp = &c;
    cout << bp->isHeavy() << endl;
}
*/
// What is the output and why?
//
// A) Compiler error: len is private in Book
// B) true (uses Comic::isHeavy because it's polymorphic)
// C) false (uses Book::isHeavy because method is non-virtual)
// D) Undefined behavior
// E) 1 (uses Comic::isHeavy and casts bool to int)
//
// YOUR ANSWER: _____

// Q8 [MEDIUM] - Multiple Choice
// With virtual methods, which type determines which method is called?
//
// A) The static type (type of the pointer/reference)
// B) The dynamic type (actual object type at runtime)
// C) The type used in the most recent cast
// D) Whichever type appears first in the inheritance hierarchy
// E) It depends on whether you use -> or .
//
// YOUR ANSWER: _____

// Q9 [HARD] - Multiple Choice
/*
class Base {
public:
    virtual void foo() { cout << "Base::foo" << endl; }
    void bar() { foo(); }
};

class Derived : public Base {
public:
    void foo() override { cout << "Derived::foo" << endl; }
};

int main() {
    Derived d;
    Base* bp = &d;
    bp->bar();
}
*/
// What is printed?
//
// A) "Base::foo"
// B) "Derived::foo"
// C) Both "Base::foo" and "Derived::foo"
// D) Compiler error: bar() is not virtual
// E) Nothing, the program doesn't compile
//
// YOUR ANSWER: _____

// Q10 [HARD] - TRUE/FALSE
// The override keyword is required in C++ to override a virtual method;
// without it, the method will not override the base class version.
//
// YOUR ANSWER: _____

// Q11 [EXTREMELY HARD] - Multiple Choice
/*
class A {
public:
    virtual void f() { cout << "A::f" << endl; }
    void g() { f(); }
};

class B : public A {
public:
    void f() override { cout << "B::f" << endl; }
    void g() { f(); }
};

int main() {
    B b;
    A& ar = b;
    ar.g();
}
*/
// What is printed?
//
// A) "A::f"
// B) "B::f"
// C) "A::f" followed by "B::f"
// D) Compiler error: ambiguous call to g()
// E) Undefined behavior
//
// YOUR ANSWER: _____

// Q12 [MEDIUM] - TRUE/FALSE
// If a base class method is virtual, all derived class methods with the same
// signature are automatically virtual, even without the virtual keyword.
//
// YOUR ANSWER: _____


// ============================================================================
// SECTION 3: VIRTUAL DESTRUCTORS (Questions 13-16)
// ============================================================================

// Q13 [EASY] - TRUE/FALSE
// If a class has any virtual methods, its destructor should be virtual.
//
// YOUR ANSWER: _____

// Q14 [MEDIUM] - Multiple Choice
/*
class X {
    int* xarr;
public:
    X(int n) : xarr{new int[n]} {}
    ~X() { delete[] xarr; cout << "~X" << endl; }
};

class Y : public X {
    int* yarr;
public:
    Y(int m, int n) : X{m}, yarr{new int[n]} {}
    ~Y() { delete[] yarr; cout << "~Y" << endl; }
};

int main() {
    X* myY = new Y{1, 2};
    delete myY;
}
*/
// What is printed and what happens?
//
// A) "~Y" followed by "~X", no memory leak
// B) "~X" only, memory leak (yarr never deleted)
// C) "~X" followed by "~Y", no memory leak
// D) Compiler error: cannot delete through base pointer
// E) Nothing printed, complete memory leak
//
// YOUR ANSWER: _____

// Q15 [HARD] - Multiple Choice
// In what order are destructors called in an inheritance hierarchy?
//
// A) Base destructor → Derived destructor
// B) Derived destructor body → Derived fields → Base destructor
// C) Derived destructor → Base fields → Base destructor
// D) All destructors run simultaneously
// E) Base fields → Base destructor → Derived fields → Derived destructor
//
// YOUR ANSWER: _____

// Q16 [EXTREMELY HARD] - TRUE/FALSE
// A pure virtual destructor must be declared as virtual ~ClassName() = 0;
// and does not need to be defined (implemented) anywhere.
//
// YOUR ANSWER: _____


// ============================================================================
// SECTION 4: POLYMORPHISM AND ARRAYS (Questions 17-20)
// ============================================================================

// Q17 [MEDIUM] - TRUE/FALSE
// You can safely store derived class objects in an array and access them
// polymorphically through a base class pointer to the array.
//
// YOUR ANSWER: _____

// Q18 [HARD] - Multiple Choice
/*
class Animal {
    int weight;
public:
    Animal(int w) : weight{w} {}
    virtual void speak() = 0;
};

class Dog : public Animal {
    string breed;
public:
    Dog(int w, string b) : Animal{w}, breed{b} {}
    void speak() override { cout << "Woof" << endl; }
};

int main() {
    Dog dogs[3] = {Dog{10, "Beagle"}, Dog{20, "Poodle"}, Dog{15, "Husky"}};
    Animal* ptr = dogs;
    ptr[1].speak();
}
*/
// What happens?
//
// A) Prints "Woof" correctly
// B) Compiler error: cannot convert Dog[] to Animal*
// C) Data misalignment: ptr[1] doesn't point to second dog
// D) Virtual dispatch fails, calls Animal::speak()
// E) Segmentation fault at runtime
//
// YOUR ANSWER: _____

// Q19 [MEDIUM] - Multiple Choice
// What is the correct way to create a polymorphic array?
//
// A) Animal animals[3] = {Dog{}, Cat{}, Bird{}};
// B) Animal* animals[3] = {new Dog{}, new Cat{}, new Bird{}};
// C) vector<Animal> animals = {Dog{}, Cat{}, Bird{}};
// D) Dog* animals[3] = {new Dog{}, new Dog{}, new Dog{}};
// E) Both A and C are correct
//
// YOUR ANSWER: _____

// Q20 [HARD] - TRUE/FALSE
// The reason array polymorphism fails is because pointer arithmetic uses
// sizeof(BaseClass) instead of sizeof(DerivedClass), causing misalignment.
//
// YOUR ANSWER: _____


// ============================================================================
// SECTION 5: CASTING AND RTTI (Questions 21-25)
// ============================================================================

// Q21 [EASY] - Multiple Choice
// Which cast performs runtime type checking?
//
// A) static_cast
// B) dynamic_cast
// C) const_cast
// D) reinterpret_cast
// E) c-style cast
//
// YOUR ANSWER: _____

// Q22 [MEDIUM] - TRUE/FALSE
// dynamic_cast can be used on any class, regardless of whether it has
// virtual methods.
//
// YOUR ANSWER: _____

// Q23 [MEDIUM] - Multiple Choice
/*
class Book {
public:
    virtual ~Book() {}
};
class Text : public Book { };

int main() {
    Book* b = new Book{};
    Text* t = dynamic_cast<Text*>(b);
}
*/
// What is the value of t after the dynamic_cast?
//
// A) Points to the same object as b
// B) nullptr
// C) Throws std::bad_cast exception
// D) Undefined behavior
// E) Compiler error: cannot cast Book to Text
//
// YOUR ANSWER: _____

// Q24 [HARD] - Multiple Choice
// What is required for dynamic_cast to work on a class hierarchy?
//
// A) At least one virtual method in the base class
// B) A virtual destructor in the base class
// C) All methods must be virtual
// D) The class must be abstract
// E) No requirements, it always works
//
// YOUR ANSWER: _____

// Q25 [HARD] - Multiple Choice
/*
class Base {
public:
    virtual ~Base() {}
};
class Derived : public Base { };

int main() {
    Base b;
    try {
        Derived& d = dynamic_cast<Derived&>(b);
    } catch (std::bad_cast& e) {
        cout << "Cast failed" << endl;
    }
}
*/
// What happens?
//
// A) Prints "Cast failed"
// B) d references b successfully
// C) Compiler error: cannot cast reference
// D) Undefined behavior
// E) Segmentation fault
//
// YOUR ANSWER: _____


// ============================================================================
// SECTION 6: VTABLES AND MEMORY LAYOUT (Questions 26-29)
// ============================================================================

// Q26 [MEDIUM] - Multiple Choice
/*
class Vec1 {
    int x, y;
    int foo() { return x; }
};

class Vec2 {
    int x, y;
    virtual int foo() { return x; }
};
*/
// How do the sizes of Vec1 and Vec2 compare on a 64-bit system?
//
// A) sizeof(Vec1) == sizeof(Vec2) == 8 bytes
// B) sizeof(Vec1) == 8 bytes, sizeof(Vec2) == 12 bytes
// C) sizeof(Vec1) == 8 bytes, sizeof(Vec2) == 16 bytes
// D) sizeof(Vec1) == 12 bytes, sizeof(Vec2) == 16 bytes
// E) They are the same size, virtual doesn't affect memory
//
// YOUR ANSWER: _____

// Q27 [HARD] - TRUE/FALSE
// Each object of a class with virtual methods contains its own copy of the
// vtable.
//
// YOUR ANSWER: _____

// Q28 [HARD] - Multiple Choice
// What does the vptr (virtual pointer) in an object point to?
//
// A) The next object in memory
// B) The base class object
// C) The vtable for that object's class
// D) The virtual destructor
// E) The first virtual method
//
// YOUR ANSWER: _____

// Q29 [EXTREMELY HARD] - Multiple Choice
// When is virtual dispatch (vtable lookup) performed?
//
// A) At compile time
// B) At runtime, every time a method is called
// C) At runtime, only for virtual methods called through pointers/references
// D) At runtime, for all method calls
// E) During object construction
//
// YOUR ANSWER: _____


// ============================================================================
// SECTION 7: COPY/MOVE SEMANTICS WITH INHERITANCE (Questions 30-33)
// ============================================================================

// Q30 [MEDIUM] - TRUE/FALSE
// When defining a copy constructor for a derived class, you must explicitly
// call the base class copy constructor in the member initialization list.
//
// YOUR ANSWER: _____

// Q31 [HARD] - Multiple Choice
/*
class Book {
    string title;
public:
    Book(const Book& other) : title{other.title} {}
};

class Text : public Book {
    string topic;
    // No copy constructor defined
};

int main() {
    Text t1;
    Text t2 = t1;
}
*/
// What happens when t2 is copy constructed from t1?
//
// A) Compiler error: Text has no copy constructor
// B) Only Book's copy constructor runs, topic is uninitialized
// C) Book's copy constructor runs, topic is default-initialized
// D) Compiler generates Text copy constructor that calls Book's copy ctor
// E) Shallow copy of both title and topic
//
// YOUR ANSWER: _____

// Q32 [HARD] - Multiple Choice
// When implementing a move constructor for a derived class, how should you
// pass the parameter to the base class move constructor?
//
// A) Base{other}
// B) Base{std::move(other)}
// C) Base{static_cast<Base&&>(other)}
// D) Both B and C are correct
// E) Base class move constructor is called automatically
//
// YOUR ANSWER: _____

// Q33 [EXTREMELY HARD] - Multiple Choice
/*
class A {
    int* data;
public:
    A() : data{new int{0}} {}
    virtual ~A() { delete data; }
    virtual A& operator=(const A& other) {
        if (this == &other) return *this;
        delete data;
        data = new int{*other.data};
        return *this;
    }
};

class B : public A {
    int* moreData;
public:
    B() : A{}, moreData{new int{0}} {}
    ~B() override { delete moreData; }
};

int main() {
    B b1;
    A* a = new B{};
    *a = b1;  // Assignment through base pointer
    delete a;
}
*/
// What problem exists in this code?
//
// A) Memory leak: moreData is never deleted
// B) Double delete on data
// C) Partial assignment: only A's fields are assigned, B's fields ignored
// D) Slicing occurs during assignment
// E) No problem, code is correct
//
// YOUR ANSWER: _____


// ============================================================================
// SECTION 8: PURE VIRTUAL AND ABSTRACT CLASSES (Questions 34-36)
// ============================================================================

// Q34 [EASY] - TRUE/FALSE
// A class with at least one pure virtual method cannot be instantiated.
//
// YOUR ANSWER: _____

// Q35 [MEDIUM] - Multiple Choice
/*
class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius{r} {}
    // No draw() implementation
};

int main() {
    Circle c{5.0};
}
*/
// What happens?
//
// A) Compiles and runs successfully
// B) Compiler error: Circle is still abstract
// C) Compiler error: cannot instantiate Shape
// D) Runtime error: pure virtual method called
// E) Undefined behavior
//
// YOUR ANSWER: _____

// Q36 [HARD] - TRUE/FALSE
// A pure virtual method can have an implementation in the base class, and
// derived classes can explicitly call it using Base::method().
//
// YOUR ANSWER: _____


// ============================================================================
// SECTION 9: ADVANCED SCENARIOS (Questions 37-40)
// ============================================================================

// Q37 [EXTREMELY HARD] - Multiple Choice
/*
class Base {
public:
    Base() { foo(); }
    virtual void foo() { cout << "Base::foo" << endl; }
};

class Derived : public Base {
public:
    Derived() : Base{} { }
    void foo() override { cout << "Derived::foo" << endl; }
};

int main() {
    Derived d;
}
*/
// What is printed?
//
// A) "Derived::foo"
// B) "Base::foo"
// C) Both "Base::foo" and "Derived::foo"
// D) Undefined behavior
// E) Compiler error: cannot call virtual method in constructor
//
// YOUR ANSWER: _____

// Q38 [EXTREMELY HARD] - Multiple Choice
/*
class A {
    int x;
public:
    A(int x) : x{x} {}
    virtual A* clone() { return new A{x}; }
};

class B : public A {
    int y;
public:
    B(int x, int y) : A{x}, y{y} {}
    B* clone() override { return new B{*this}; }
};

int main() {
    A* a = new B{1, 2};
    A* copy = a->clone();
    B* b = dynamic_cast<B*>(copy);
}
*/
// What is the value of b after the dynamic_cast?
//
// A) nullptr (clone() returns A*, not B*)
// B) Points to a valid B object
// C) Compiler error: covariant return types not allowed
// D) Undefined behavior
// E) Points to a sliced object
//
// YOUR ANSWER: _____

// Q39 [EXTREMELY HARD] - TRUE/FALSE
// When an exception is thrown and caught by value (not by reference), and
// then re-thrown using "throw e;", the exception can be sliced if it's a
// derived exception type.
//
// YOUR ANSWER: _____

// Q40 [EXTREMELY HARD] - Multiple Choice
/*
class Base {
protected:
    int x;
public:
    Base(int x) : x{x} {}
    friend bool operator==(const Base& a, const Base& b) {
        return a.x == b.x;
    }
};

class Derived : public Base {
    int y;
public:
    Derived(int x, int y) : Base{x}, y{y} {}
};

int main() {
    Derived d1{1, 2};
    Derived d2{1, 3};
    cout << (d1 == d2) << endl;
}
*/
// What is printed and why?
//
// A) 0 (false), because y values differ
// B) 1 (true), because only x values are compared
// C) Compiler error: operator== not defined for Derived
// D) Undefined behavior
// E) Compiler error: cannot access protected member x
//
// YOUR ANSWER: _____


// ============================================================================
// END OF THEORY QUESTIONS
// ============================================================================
// Total: 40 Questions
// Difficulty Distribution:
//   - Easy: 6 questions
//   - Medium: 16 questions
//   - Hard: 12 questions
//   - Extremely Hard: 6 questions
//
// Topics Covered:
//   - Object Slicing (5 questions)
//   - Virtual vs Non-Virtual Methods (7 questions)
//   - Virtual Destructors (4 questions)
//   - Polymorphism and Arrays (4 questions)
//   - Casting and RTTI (5 questions)
//   - Vtables and Memory Layout (4 questions)
//   - Copy/Move Semantics with Inheritance (4 questions)
//   - Pure Virtual and Abstract Classes (3 questions)
//   - Advanced Scenarios (4 questions)
//
// Check THEORY_ANSWERS.cpp for detailed explanations!
// ============================================================================

int main() {
    cout << "CS246 Comprehensive Theory Questions" << endl;
    cout << "Answer all 40 questions above" << endl;
    cout << "Check THEORY_ANSWERS.cpp for detailed solutions" << endl;
    return 0;
}
