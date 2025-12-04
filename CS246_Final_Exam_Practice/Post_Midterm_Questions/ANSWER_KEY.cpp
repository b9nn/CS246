// ============================================================================
// CS246 Final Exam Practice - Post-Midterm ANSWER KEY
// Complete solutions with explanations
// ============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

// ============================================================================
// INHERITANCE AND POLYMORPHISM - ANSWERS
// ============================================================================

// Q1: Answer: B) override

// Q2: Problem: Derived can't initialize base's private members directly
class Book {
public:
    string title;
    Book(string t) : title{t} {}
};
class Comic : public Book {
public:
    string hero;
    Comic(string t, string h) : Book{t}, hero{h} {}  // Call base constructor
};

// Q3: Array polymorphism pitfall: pointer arithmetic uses base size
// When ptr[1] is accessed, advances by sizeof(Animal), not sizeof(Dog)
// Solution: Use array of pointers: Animal* dogs[3] = {new Dog{...}, ...};

// Q4: protected: Accessible in class and derived classes, not externally

// Q5: Polymorphism: Many forms - treat different types through common interface
// Example: vector<Shape*> storing Circle, Rectangle - all call draw()


// ============================================================================
// VIRTUAL METHODS AND DESTRUCTORS - ANSWERS
// ============================================================================

// Q1: Answer: D) When class is used as base class in inheritance hierarchy

// Q2: Memory leak: Base destructor not virtual
// When delete ptr executes, only Base::~Base() runs
// Derived::~Derived() never runs -> name is never deleted
class Base {
    int* data;
public:
    Base() : data{new int[10]} {}
    virtual ~Base() { delete[] data; }  // Add virtual!
};
class Derived : public Base {
    string* name;
public:
    Derived() : Base(), name{new string{"Object"}} {}
    ~Derived() override { delete name; }
};

// Q3: Pure virtual method: virtual method with = 0, no implementation
// Makes class abstract - can't instantiate directly
// virtual void method() = 0;

// Q4: Runtime dispatch: Determine which method to call at runtime
// Objects have vptr -> vtable -> correct function pointer

// Q5: Circle implementation
class Shape {
public:
    virtual void draw() = 0;
    virtual double area() = 0;
    virtual ~Shape() {}
};
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius{r} {}
    void draw() override {
        cout << "Drawing circle with radius " << radius << endl;
    }
    double area() override {
        return 3.14159 * radius * radius;
    }
};

// Q6: Answer: B) Derived dtor body -> Derived fields -> Base dtor

// Q7: Employee hierarchy
class Employee {
protected:
    string name;
    int employeeID;
public:
    Employee(string n, int id) : name{n}, employeeID{id} {}
    virtual double calculatePay() = 0;
    virtual void displayInfo() {
        cout << "Name: " << name << ", ID: " << employeeID << endl;
    }
    virtual ~Employee() {}
};
class HourlyEmployee : public Employee {
    double hourlyRate, hoursWorked;
public:
    HourlyEmployee(string n, int id, double rate, double hours)
        : Employee{n, id}, hourlyRate{rate}, hoursWorked{hours} {}
    double calculatePay() override { return hourlyRate * hoursWorked; }
    void displayInfo() override {
        Employee::displayInfo();
        cout << "Pay: $" << calculatePay() << endl;
    }
};


// ============================================================================
// EXCEPTIONS AND SAFETY - ANSWERS
// ============================================================================

// Q1: Answer: C) catch (Exception& e)
// Catch by reference for polymorphism and avoid copying

// Q2: throw; re-throws original (polymorphic), throw e; throws sliced copy

// Q3: Exception unwinding
void funcC() { throw runtime_error{"Error"}; }
void funcB() { funcC(); }
void funcA() {
    try { funcB(); }
    catch (runtime_error& e) { cout << "Caught: " << e.what() << endl; }
}
// Stack unwinds: funcC -> funcB -> funcA, destructors called

// Q4: Exception guarantees:
// 1. No-throw: Never throws, marked noexcept
// 2. Strong: If throws, state unchanged (transactional)
// 3. Basic: If throws, valid but unspecified state

// Q5: Answer: D) No-throw guarantee (noexcept)

// Q6: push_back with strong guarantee
class MyVector {
    int* data;
    int size, capacity;
public:
    MyVector() : data{nullptr}, size{0}, capacity{0} {}
    void push_back(int value) {
        if (size == capacity) {
            int newCap = (capacity == 0) ? 1 : capacity * 2;
            int* newData = new int[newCap];
            for (int i = 0; i < size; ++i) newData[i] = data[i];
            newData[size] = value;
            delete[] data;
            data = newData;
            capacity = newCap;
            size++;
        } else {
            data[size++] = value;
        }
    }
    ~MyVector() { delete[] data; }
};

// Q8: Local objects destructed during unwinding, RAII ensures cleanup

// Q9: Catch order: Most specific first
// catch (FileNotFound&) {}
// catch (FilePermissionDenied&) {}
// catch (FileException&) {}


// ============================================================================
// SMART POINTERS AND RAII - ANSWERS
// ============================================================================

// Q1: Answer: B) unique_ptr

// Q2: Using unique_ptr
void processData_SMART() {
    auto data = make_unique<int[]>(100);
    if (true) return;  // Automatic cleanup
}

// Q3: Answer: C) Compilation error - copying deleted

// Q4: unique_ptr: exclusive ownership, move-only, no overhead
// shared_ptr: shared ownership, copyable, reference counting overhead
// Use unique_ptr by default, shared_ptr for multiple owners

// Q5: RAII: Resource lifetime tied to object lifetime
class File {
    FILE* fp;
public:
    File(const char* name) : fp{fopen(name, "r")} {}
    ~File() { if (fp) fclose(fp); }
};

// Q7: Linked list with shared_ptr
class Node {
public:
    int data;
    shared_ptr<Node> next;
    Node(int d) : data{d}, next{nullptr} {}
};
void createList() {
    auto head = make_shared<Node>(1);
    head->next = make_shared<Node>(2);
}

// Q8: .get() returns raw pointer, needed for legacy APIs

// Q9: Answer: D) Both B and C, but C (make_unique) is preferred

// Q10: shared_ptr: reference count, when 0 -> delete
// Circular references prevent count reaching 0, use weak_ptr


// ============================================================================
// DESIGN PATTERNS - ANSWERS
// ============================================================================

// FACTORY PATTERN
class Enemy {
public:
    virtual void attack() = 0;
    virtual ~Enemy() {}
};
class Turtle : public Enemy {
public:
    void attack() override { cout << "Turtle!" << endl; }
};
class Bullet : public Enemy {
public:
    void attack() override { cout << "Bullet!" << endl; }
};
class Level {
public:
    virtual Enemy* createEnemy() = 0;
    virtual ~Level() {}
};
class EasyLevel : public Level {
public:
    Enemy* createEnemy() override {
        return (rand() % 2) ? new Turtle{} : new Bullet{};
    }
};

// DECORATOR PATTERN
class Coffee {
public:
    virtual double cost() = 0;
    virtual string description() = 0;
    virtual ~Coffee() {}
};
class Espresso : public Coffee {
public:
    double cost() override { return 2.00; }
    string description() override { return "Espresso"; }
};
class CoffeeDecorator : public Coffee {
protected:
    Coffee* coffee;
public:
    CoffeeDecorator(Coffee* c) : coffee{c} {}
    virtual ~CoffeeDecorator() { delete coffee; }
};
class Milk : public CoffeeDecorator {
public:
    Milk(Coffee* c) : CoffeeDecorator{c} {}
    double cost() override { return coffee->cost() + 0.50; }
    string description() override { return coffee->description() + " + Milk"; }
};

// Q4: Answer: B) Avoids explosion of subclass combinations

// OBSERVER PATTERN
class Observer {
public:
    virtual void notify() = 0;
    virtual ~Observer() {}
};
class Subject {
    vector<Observer*> observers;
public:
    void attach(Observer* ob) { observers.push_back(ob); }
    void detach(Observer* ob) {
        observers.erase(remove(observers.begin(), observers.end(), ob));
    }
    void notifyObservers() {
        for (auto ob : observers) ob->notify();
    }
};

// TEMPLATE METHOD PATTERN
class Turtle_Template {
public:
    void draw() { drawHead(); drawShell(); drawFeet(); }
    virtual ~Turtle_Template() {}
private:
    void drawHead() {}
    void drawFeet() {}
    virtual void drawShell() = 0;
};
class RedTurtle : public Turtle_Template {
    void drawShell() override { cout << "Red shell" << endl; }
};

// NVI PATTERN
class GameCharacter {
public:
    int healthValue() {  // Public non-virtual
        return doHealthValue();
    }
private:
    virtual int doHealthValue() { return 100; }  // Private virtual
};

// Q13: Answer: B) Depend on abstract base classes

// Q14: Coupling: interdependence (want LOW)
// Cohesion: internal focus (want HIGH)


// ============================================================================
// TEMPLATES AND ITERATORS - ANSWERS
// ============================================================================

// Q1: Maximum template
template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

// Q2: Type T must support operator<

// Q3: Print array
template <typename T>
void printArray(T arr[], int size) {
    for (int i = 0; i < size; ++i) cout << arr[i] << " ";
    cout << endl;
}

// Q5: Sum with iterators
template <typename Iter>
int sum(Iter begin, Iter end) {
    int total = 0;
    for (auto it = begin; it != end; ++it) total += *it;
    return total;
}

// Q6: Answer: B) Compiler deduces template types from arguments

// Q7: Variadic templates
void print() {}
template <typename T, typename... Args>
void print(T first, Args... rest) {
    cout << first << " ";
    print(rest...);
}

// Q8: maximum(5, 3.14) fails: different types (int vs double)
// Fix: maximum<double>(5, 3.14) or use two template parameters

// Q10: Contains function
template <typename Iter, typename T>
bool contains(Iter begin, Iter end, T value) {
    for (auto it = begin; it != end; ++it)
        if (*it == value) return true;
    return false;
}


// ============================================================================
// CASTING - ANSWERS
// ============================================================================

// Q1: Answer: B) static_cast

// Q2: static_cast: compile-time, no checking, related types
// dynamic_cast: runtime checking, polymorphic types, returns nullptr if fails

// Q3: Safe downcasting
void testCasting() {
    Animal* ptr = new Animal{};
    Dog* dogPtr = dynamic_cast<Dog*>(ptr);
    if (dogPtr) dogPtr->fetch();
    else cout << "Not a dog" << endl;
    delete ptr;
}

// Q4: Answer: B) Returns nullptr

// Q5: Requires: at least one virtual method (for vtable/RTTI)

// Q7: a) static_cast, b) dynamic_cast, c) const_cast, d) reinterpret_cast

// Q8: Answer: B) More explicit about intent and safer


int main() {
    cout << "Post-Midterm Answer Key - See comments for solutions" << endl;
    return 0;
}
