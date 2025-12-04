// ============================================================================
// CS246 Final Exam Practice - Pre-Midterm ANSWER KEY
// Complete solutions with explanations
// ============================================================================

#include <iostream>
#include <string>
using namespace std;

// ============================================================================
// COMPILATION AND MODULES - ANSWERS
// ============================================================================

// Q1: Answer: B) -c
// The -c flag compiles source files into object files without linking

// Q2: Compilation commands:
// g++ -std=c++14 -c student.cc
// g++ -std=c++14 -c main.cc
// g++ -std=c++14 student.o main.o -o program
//
// OR in a single command:
// g++ -std=c++14 student.cc main.cc -o program

// Q3: DECLARATION vs DEFINITION
// Declaration: Tells compiler that something exists (name and type)
// Definition: Provides actual implementation/storage
//
// Example:
// int add(int a, int b);           // Declaration
// int add(int a, int b) {          // Definition
//     return a + b;
// }

// Q4: Header guards prevent MULTIPLE INCLUSION of the same header
// Without guards, including a header twice causes redefinition errors


// ============================================================================
// MEMORY MANAGEMENT - ANSWERS
// ============================================================================

// Q1: Answer: B) int* p = new int{5};
// The 'new' keyword allocates memory on the heap

// Q2: Fixed version with memory leaks removed
struct Node {
    int data;
    Node* next;
};

void processNodes_FIXED() {
    Node* head = new Node{1, nullptr};
    Node* second = new Node{2, nullptr};
    head->next = second;

    // Don't create new temp - just use it
    Node* temp = head->next;

    // Clean up all allocated memory
    delete second;  // or delete head->next;
    delete head;
}
// Leaks: 1) temp = new Node{3, nullptr} is immediately overwritten
//        2) second is never deleted

// Q3: Stack vs Heap
// STACK:
//   Advantages: Fast, automatic deallocation
//   Disadvantage: Limited size, lifetime limited to scope
// HEAP:
//   Advantages: Large, flexible lifetime
//   Disadvantage: Manual management required, slower

// Q4: Problem: Returns pointer to local array (stack allocated)
// When function returns, array is destroyed -> undefined behavior
int* createArray_FIXED() {
    int* arr = new int[5]{1, 2, 3, 4, 5};  // Allocate on heap
    return arr;  // Caller must delete[]
}

// Q5: Dereferencing nullptr causes undefined behavior (usually crash)
// Uninitialized pointers contain garbage values


// ============================================================================
// CLASSES AND OBJECTS - ANSWERS
// ============================================================================

// Q1: Answer: B) Initializing a const field
// Const fields must be initialized using MIL (also references)

// Q2: Constructor with MIL
class Book {
    const string author;
    string& title;
    int pages;
public:
    Book(string a, string& t, int p) : author{a}, title{t}, pages{p} {}
    // Why MIL required:
    // - author is const: can't assign after initialization
    // - title is reference: must be bound at initialization
};

// Q3: Three steps of object creation:
// 1. Allocation - space allocated (stack/heap)
// 2. Field construction - fields constructed via MIL
// 3. Constructor body execution

// Q4: Friend functions access private members, breaking encapsulation
// Justified for operator<<: needs private access but must be non-member

// Q5: Operator<< overloading
class Student {
    int id;
    string name;
public:
    Student(int id, string name) : id{id}, name{name} {}

    friend ostream& operator<<(ostream& out, const Student& s);
};

ostream& operator<<(ostream& out, const Student& s) {
    out << "Student[ID: " << s.id << ", Name: " << s.name << "]";
    return out;
}


// ============================================================================
// COPYING AND MOVING - ANSWERS
// ============================================================================

// Q1: Answer: C) 5 + 3
// R-values are temporary values without persistent addresses

// Q2: The Big 5:
// COPYING: 1. Copy constructor, 2. Copy assignment operator
// MOVING: 3. Move constructor, 4. Move assignment operator
// RESOURCE: 5. Destructor

// Q3: Copy constructor
class IntArray {
    int* data;
    int size;
public:
    IntArray(int n) : data{new int[n]}, size{n} {}

    IntArray(const IntArray& other)
        : data{new int[other.size]}, size{other.size} {
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
    }

    ~IntArray() { delete[] data; }
};

// Q4: Copy assignment and move constructor
class IntArray_Full {
    int* data;
    int size;
public:
    IntArray_Full(int n) : data{new int[n]}, size{n} {}

    // Copy assignment
    IntArray_Full& operator=(const IntArray_Full& other) {
        if (this == &other) return *this;
        delete[] data;
        size = other.size;
        data = new int[size];
        for (int i = 0; i < size; ++i) {
            data[i] = other.data[i];
        }
        return *this;
    }

    // Move constructor
    IntArray_Full(IntArray_Full&& other)
        : data{other.data}, size{other.size} {
        other.data = nullptr;
        other.size = 0;
    }

    ~IntArray_Full() { delete[] data; }
};

// Q5: L-values have addresses, R-values are temporary
// Move semantics avoid expensive copies by transferring ownership
// Compiler uses move: returning locals, passing temporaries, std::move()

// Q6: Without copy constructor, compiler generates shallow copy
// Multiple objects share same heap memory -> double delete bug

// Q7: Answer: C) Copy assignment operator
// b already exists (assignment), a is L-value (copy not move)


// ============================================================================
// OPERATOR OVERLOADING - ANSWERS
// ============================================================================

// Q1: operator<< left operand is ostream (cout), not your class
// Must be non-member: operator<<(ostream&, const Student&)

// Q2: Vector addition
class Vector2D {
    double x, y;
public:
    Vector2D(double x, double y) : x{x}, y{y} {}
    double getX() const { return x; }
    double getY() const { return y; }

    Vector2D operator+(const Vector2D& other) const {
        return Vector2D{x + other.x, y + other.y};
    }
};

// Q3: Input operator
class Point {
    int x, y;
public:
    Point() : x{0}, y{0} {}
    friend istream& operator>>(istream& in, Point& p);
};

istream& operator>>(istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

// Q4: Answer: C) A reference to *this
// Allows chaining: a = b = c;


// ============================================================================
// COMMON MISTAKES TO AVOID
// ============================================================================

// 1. Forgetting to use MIL for const/reference members
// 2. Shallow copy leading to double delete
// 3. Not returning *this in assignment operators
// 4. Non-virtual destructors in inheritance hierarchies
// 5. Forgetting to initialize pointers to nullptr
// 6. Memory leaks from not deleting heap allocations
// 7. Returning pointers to local variables
// 8. Using operator= when copy constructor is needed (and vice versa)

int main() {
    cout << "Pre-Midterm Answer Key - See comments for solutions" << endl;
    return 0;
}
