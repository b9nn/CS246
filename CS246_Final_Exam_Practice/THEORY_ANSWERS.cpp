// ============================================================================
// CS246 COMPREHENSIVE THEORY QUESTIONS - COMPLETE ANSWER KEY
// Detailed Explanations with Technical Correctness
// ============================================================================

#include <iostream>
#include <memory>
#include <string>
using namespace std;

// ============================================================================
// SECTION 1: OBJECT SLICING - ANSWERS
// ============================================================================

// Q1 ANSWER: FALSE
//
// EXPLANATION:
// Object slicing occurs when a derived class object is assigned to a BASE
// CLASS OBJECT (not pointer). Assignment to a pointer or reference does NOT
// cause slicing because pointers and references are fixed-size (8 bytes on
// 64-bit systems) and simply hold addresses.
//
// Example:
//   Derived d;
//   Base b = d;      // SLICING OCCURS - d is copied into b
//   Base* bp = &d;   // NO SLICING - bp just holds d's address
//   Base& br = d;    // NO SLICING - br is an alias for d
//
// KEY CONCEPT: Slicing happens during object copying when the derived portion
// cannot fit into the base object's memory layout.
// ============================================================================


// Q2 ANSWER: A) Line A only
//
// EXPLANATION:
// Line A: Book b = c;
//   - This creates a Book object and copy-constructs it from Comic c
//   - The Book object has space for Book's fields only (just 'length')
//   - The Comic-specific field 'hero' is lost → SLICING
//
// Line B: Book* bp = &c;
//   - bp is a pointer (8 bytes on 64-bit system)
//   - It stores the address of c, which is still a complete Comic object
//   - NO SLICING - pointer doesn't copy the object
//
// Line C: Book& br = c;
//   - br is a reference, which is just an alias for c
//   - c remains a complete Comic object
//   - NO SLICING - reference doesn't create a new object
//
// TECHNICAL DETAIL: Slicing only occurs during value semantics (copy), not
// reference semantics (pointers/references).
// ============================================================================


// Q3 ANSWER: FALSE
//
// EXPLANATION:
// This is a critical misconception. When object slicing occurs:
// 1. The derived class fields ARE lost (correct)
// 2. Virtual method dispatch DOES NOT work (the false part)
//
// Why virtual dispatch fails after slicing:
// - A sliced object IS a Base object, not a Derived object
// - It contains only Base's vptr, pointing to Base's vtable
// - Even if the method is virtual, it calls Base's version
//
// Example:
//   class Base { public: virtual void foo() { cout << "Base"; } };
//   class Derived : public Base { public: void foo() override { cout << "Derived"; } };
//
//   Derived d;
//   Base b = d;     // Slicing - b is genuinely a Base object now
//   b.foo();        // Prints "Base" - not polymorphic anymore!
//
// CONTRAST WITH POINTER:
//   Base* bp = &d;
//   bp->foo();      // Prints "Derived" - polymorphism works!
//
// REASON: After slicing, the object's dynamic type IS Base, not Derived.
// There's no Derived subobject remaining.
// ============================================================================


// Q4 ANSWER: A) "Base copy" only
//
// EXPLANATION:
// When you write: Base b = d;
//
// Step-by-step execution:
// 1. Compiler sees: "Create a Base object from a Derived object"
// 2. Compiler looks for: Base::Base(const Base&)
// 3. Derived IS-A Base, so d can bind to const Base& parameter
// 4. Only Base's copy constructor runs
// 5. Derived's copy constructor is NEVER called
//
// This prints "Base copy" only.
//
// WHY NOT DERIVED'S COPY CONSTRUCTOR?
// - We're constructing a Base object, not a Derived object
// - The Derived copy constructor signature is: Derived(const Derived&)
// - This doesn't match what we're doing (creating a Base)
//
// MEMORY LAYOUT:
//   Before:  d = [Base: x=1][Derived: y=2]
//   After:   b = [Base: x=1]
//   The y field is sliced away.
//
// IMPORTANT: This is different from:
//   Derived d2 = d;  // Calls Derived copy ctor, prints both messages
// ============================================================================


// Q5 ANSWER: B) Object slicing occurs when passing to foo, only A's fields are copied
//
// EXPLANATION:
// Let's trace the execution:
//
// 1. B b{1, 2};
//    - Creates a B object: [A: x=1][B: y=2]
//
// 2. A* ap = &b;
//    - ap points to the A subobject within b
//    - No slicing yet (it's just a pointer)
//
// 3. foo(*ap);
//    - *ap dereferences the pointer, yielding an A& (reference to A subobject)
//    - foo expects A by value: void foo(A a)
//    - The A copy constructor is called: A(const A& other)
//    - Only A's fields are copied into the parameter a
//    - SLICING OCCURS HERE
//
// TECHNICAL DETAIL:
// - Even though ap points to a B object, *ap has static type A&
// - When passed by value, only the A portion is copied
// - The B-specific fields (y) are lost in the copy
//
// WHY NOT C?
// - C would be correct if foo took A& or A* (no copy, no slicing)
// - But foo takes A by value, forcing a copy
//
// KEY LESSON: Passing by value through a base reference/pointer causes slicing.
// Always pass polymorphic objects by pointer or reference.
// ============================================================================


// ============================================================================
// SECTION 2: VIRTUAL VS NON-VIRTUAL METHODS - ANSWERS
// ============================================================================

// Q6 ANSWER: TRUE
//
// EXPLANATION:
// "Overriding" has a specific technical meaning in C++:
// - For true overriding, the base method must be virtual
// - Without virtual, derived class methods with the same name HIDE the base
//   method (name hiding/shadowing), they don't override it
//
// However, you CAN define a method with the same signature in the derived class:
//
//   class Base {
//   public:
//       void foo() { cout << "Base"; }  // Non-virtual
//   };
//
//   class Derived : public Base {
//   public:
//       void foo() { cout << "Derived"; }  // Hides, doesn't override
//   };
//
// The key difference:
//   Derived d;
//   Base* bp = &d;
//   bp->foo();  // Calls Base::foo (static binding)
//
// If Base::foo were virtual:
//   bp->foo();  // Would call Derived::foo (dynamic binding/polymorphism)
//
// TERMINOLOGY:
// - Virtual method + same signature = OVERRIDING (polymorphic)
// - Non-virtual method + same signature = HIDING/SHADOWING (non-polymorphic)
// ============================================================================


// Q7 ANSWER: A) Compiler error: len is private in Book
//
// EXPLANATION:
// This is a compilation error for a subtle reason:
//
// In Comic::isHeavy():
//   bool isHeavy() { return len > 30; }
//                           ^^^
//
// The field 'len' is private in Book. Derived classes CANNOT access private
// members of the base class, even if they inherit them.
//
// THE CODE WON'T COMPILE.
//
// If 'len' were protected or if Comic used a public getter:
//   class Book {
//   protected:  // or public accessor
//       int len;
//   };
//
// Then the answer would be C:
// - The method is non-virtual
// - bp has static type Book*
// - Static binding chooses Book::isHeavy()
// - Output: false (or 0)
//
// KEY LESSON:
// - Private members are NOT accessible to derived classes
// - Use protected for members that derived classes need
// - Or provide protected accessor methods
// ============================================================================


// Q8 ANSWER: B) The dynamic type (actual object type at runtime)
//
// EXPLANATION:
// This is the fundamental difference between virtual and non-virtual methods:
//
// VIRTUAL METHODS:
// - Use DYNAMIC BINDING (runtime polymorphism)
// - The actual object type (dynamic type) determines which method runs
// - Determined at RUNTIME via vtable lookup
//
// Example:
//   Base* bp = new Derived{};
//   bp->virtualMethod();  // Calls Derived::virtualMethod()
//   // Static type: Base*
//   // Dynamic type: Derived
//   // Virtual → uses dynamic type
//
// NON-VIRTUAL METHODS:
// - Use STATIC BINDING (compile-time resolution)
// - The pointer/reference type (static type) determines which method runs
// - Determined at COMPILE TIME
//
// Example:
//   Base* bp = new Derived{};
//   bp->nonVirtualMethod();  // Calls Base::nonVirtualMethod()
//   // Uses static type (Base*)
//
// TERMINOLOGY:
// - Static type: Type of the variable/pointer/reference (known at compile time)
// - Dynamic type: Actual type of the object (known at runtime)
// - Virtual methods dispatch based on dynamic type
// ============================================================================


// Q9 ANSWER: B) "Derived::foo"
//
// EXPLANATION:
// This is a subtle but important example of virtual dispatch:
//
// Execution trace:
// 1. bp->bar() is called
//    - bar() is non-virtual, so Base::bar() is selected (static binding)
//
// 2. Inside Base::bar():
//    void bar() { foo(); }
//
// 3. foo() is called
//    - Within Base::bar(), "foo()" is equivalent to "this->foo()"
//    - this points to the Derived object (dynamic type)
//    - foo() is VIRTUAL
//    - Virtual dispatch looks up Derived::foo() in the vtable
//
// 4. Derived::foo() executes, printing "Derived::foo"
//
// KEY INSIGHT:
// Even though bar() is non-virtual and we're in Base::bar(), the call to
// foo() still uses virtual dispatch because:
// - foo() is virtual
// - It's called on 'this', which points to a Derived object
//
// This is why NVI (Non-Virtual Interface) pattern works:
// - Public non-virtual method (bar) provides interface
// - Calls private virtual method (foo) for customization
// - Derived classes override the virtual part
// ============================================================================


// Q10 ANSWER: FALSE
//
// EXPLANATION:
// The 'override' keyword is NOT required; it's RECOMMENDED for safety.
//
// Without override:
//   class Base {
//   public:
//       virtual void foo() {}
//   };
//
//   class Derived : public Base {
//   public:
//       void foo() {}  // Overrides Base::foo (no override keyword)
//   };
//
// This compiles and works correctly. The derived method overrides the base.
//
// WITH override (BEST PRACTICE):
//   class Derived : public Base {
//   public:
//       void foo() override {}  // Explicitly marks as override
//   };
//
// Benefits of override:
// 1. Compiler verifies there IS a base method to override
// 2. Catches typos: void fo() override {} // ERROR: no base method named fo
// 3. Catches signature mismatches: void foo(int) override {} // ERROR
// 4. Documents intent clearly
//
// COMPILER BEHAVIOR:
// - Without override: Silently creates new method if base signature differs
// - With override: Compilation error if base signature differs
//
// ALWAYS USE override IN MODERN C++!
// ============================================================================


// Q11 ANSWER: B) "B::f"
//
// EXPLANATION:
// This question tests understanding of name hiding in derived classes.
//
// The code:
//   class A {
//   public:
//       virtual void f() { cout << "A::f"; }
//       void g() { f(); }  // Calls virtual f()
//   };
//
//   class B : public A {
//   public:
//       void f() override { cout << "B::f"; }
//       void g() { f(); }  // HIDES A::g()
//   };
//
// When ar.g() is called:
// 1. ar has static type A&, dynamic type B
// 2. g() is non-virtual, so which g() is called?
//
// KEY: Static type determines non-virtual method selection
// - ar is type A&
// - A::g() is selected
//
// 3. Inside A::g():
//    void g() { f(); }
//    - Calls f() on the object
//    - f() is virtual
//    - Object is actually B
//    - Virtual dispatch → B::f()
//
// 4. Prints "B::f"
//
// IMPORTANT: B::g() exists but is NEVER called because:
// - ar has static type A&
// - g() is non-virtual
// - Static binding chooses A::g()
//
// If g() were virtual:
//   virtual void g() { f(); }
// Then B::g() would be called (which also calls f(), still printing "B::f")
// ============================================================================


// Q12 ANSWER: TRUE
//
// EXPLANATION:
// Once a method is declared virtual in a base class, it remains virtual in
// ALL derived classes, even if you don't use the 'virtual' keyword again.
//
// Example:
//   class Base {
//   public:
//       virtual void foo() {}
//   };
//
//   class Derived : public Base {
//   public:
//       void foo() {}  // Still virtual! (no keyword needed)
//   };
//
//   class MoreDerived : public Derived {
//   public:
//       void foo() {}  // Still virtual!
//   };
//
// All three foo() methods are virtual.
//
// BEST PRACTICE:
// Even though it's automatic, explicitly mark overridden methods:
//   void foo() override {}  // Clear intent
//
// Or if you want to prevent further overriding:
//   void foo() final {}  // Virtual but cannot be overridden further
//
// TECHNICAL REASON:
// - Virtual-ness is a property of the METHOD SIGNATURE in the vtable
// - Once a signature enters the vtable, it stays there for all derived classes
// - Each class's vtable can point to different implementations
// ============================================================================


// ============================================================================
// SECTION 3: VIRTUAL DESTRUCTORS - ANSWERS
// ============================================================================

// Q13 ANSWER: TRUE
//
// EXPLANATION:
// This is one of the most important rules in C++:
//
// If a class is intended to be used polymorphically (has virtual methods),
// its destructor MUST be virtual.
//
// WHY?
//   class Base {
//   public:
//       virtual void foo() {}
//       ~Base() {}  // NON-VIRTUAL - BUG!
//   };
//
//   class Derived : public Base {
//       int* data;
//   public:
//       Derived() : data{new int[100]} {}
//       ~Derived() { delete[] data; }
//   };
//
//   Base* p = new Derived{};
//   delete p;  // MEMORY LEAK!
//   // Only Base::~Base() is called
//   // Derived::~Derived() never runs
//   // data is never deleted
//
// CORRECT:
//   class Base {
//   public:
//       virtual void foo() {}
//       virtual ~Base() {}  // VIRTUAL - Correct!
//   };
//
//   delete p;  // Now Derived::~Derived() runs first, then Base::~Base()
//
// RULE OF THUMB:
// - If a class has ANY virtual method → virtual destructor
// - If a class will be inherited from → virtual destructor
// - If a class is final and never inherited → non-virtual destructor OK
// ============================================================================


// Q14 ANSWER: B) "~X" only, memory leak (yarr never deleted)
//
// EXPLANATION:
// This demonstrates the classic virtual destructor problem.
//
// What happens with: delete myY;
//
// 1. myY has static type X*
// 2. Compiler looks for X::~X()
// 3. X::~X() is NON-VIRTUAL
// 4. Static binding → only X::~X() is called
// 5. Prints "~X"
// 6. Y::~Y() is NEVER called
// 7. yarr is never deleted → MEMORY LEAK
//
// MEMORY STATE:
// - xarr is deleted (in X::~X())
// - yarr is leaked (Y::~Y() never runs)
//
// OUTPUT: "~X"
//
// THE FIX:
//   class X {
//   public:
//       virtual ~X() { delete[] xarr; cout << "~X"; }
//   };
//
// With virtual destructor:
// 1. delete myY
// 2. Virtual dispatch to actual object type (Y)
// 3. Y::~Y() runs: deletes yarr, prints "~Y"
// 4. Then Y's base subobject destructor runs: X::~X()
// 5. Prints "~X"
// 6. Output: "~Y" followed by "~X"
// 7. No memory leak!
//
// CRITICAL LESSON: Always make destructors virtual in polymorphic classes!
// ============================================================================


// Q15 ANSWER: B) Derived destructor body → Derived fields → Base destructor
//
// EXPLANATION:
// Destructor execution follows REVERSE order of construction:
//
// CONSTRUCTION ORDER:
// 1. Allocate memory
// 2. Base class constructor
// 3. Derived class fields constructed
// 4. Derived class constructor body
//
// DESTRUCTION ORDER (reverse):
// 1. Derived class destructor BODY executes
// 2. Derived class FIELDS destroyed (in reverse declaration order)
// 3. Base class destructor executes
// 4. Memory deallocated
//
// Example:
//   class Base {
//       string name;
//   public:
//       ~Base() { cout << "~Base" << endl; }
//   };
//
//   class Derived : public Base {
//       vector<int> data;
//   public:
//       ~Derived() { cout << "~Derived" << endl; }
//   };
//
//   Derived d;
// // Destruction:
// // 1. Prints "~Derived" (Derived destructor body)
// // 2. data is destroyed (vector destructor runs)
// // 3. Prints "~Base" (Base destructor body)
// // 4. name is destroyed (string destructor runs)
// // 5. Memory freed
//
// WHY THIS ORDER?
// - Derived code might use base members
// - Derived members might depend on base members
// - Must destroy derived parts before base parts become invalid
// ============================================================================


// Q16 ANSWER: FALSE
//
// EXPLANATION:
// This is a subtle point: pure virtual destructors MUST be defined!
//
// WRONG ASSUMPTION:
//   class Base {
//   public:
//       virtual ~Base() = 0;  // Pure virtual
//   };
//   // No definition provided → LINKER ERROR
//
// CORRECT:
//   class Base {
//   public:
//       virtual ~Base() = 0;
//   };
//
//   Base::~Base() {}  // MUST provide definition!
//
// WHY?
// - When a derived object is destroyed, the base destructor MUST run
// - Even though it's pure virtual, it's still called during destruction
// - Linker needs the implementation
//
// COMPARE TO OTHER PURE VIRTUAL METHODS:
//   virtual void foo() = 0;  // No definition needed (usually)
//   // Derived classes must implement; base version never called
//
// But pure virtual destructors are special:
// - Derived destructor automatically calls base destructor
// - Base destructor must exist, even if pure virtual
//
// USE CASE:
// Pure virtual destructor makes class abstract without adding other pure
// virtual methods:
//   class AbstractBase {
//   public:
//       virtual ~AbstractBase() = 0;  // Makes class abstract
//   };
//   AbstractBase::~AbstractBase() {}  // Must define
// ============================================================================


// ============================================================================
// SECTION 4: POLYMORPHISM AND ARRAYS - ANSWERS
// ============================================================================

// Q17 ANSWER: FALSE
//
// EXPLANATION:
// This is the "array polymorphism pitfall" - a common and dangerous mistake.
//
// WRONG (undefined behavior):
//   Dog dogs[3] = { Dog{10, "Beagle"}, Dog{20, "Poodle"}, Dog{15, "Husky"} };
//   Animal* ptr = dogs;
//   ptr[1].speak();  // WRONG! Data misalignment!
//
// WHY IT FAILS:
// 1. Array dogs is laid out in memory as:
//    [Dog0][Dog1][Dog2]
//    Each Dog takes sizeof(Dog) bytes
//
// 2. ptr is type Animal*
//    Pointer arithmetic: ptr[1] advances by sizeof(Animal) bytes
//
// 3. If sizeof(Dog) != sizeof(Animal):
//    ptr[1] does NOT point to Dog1!
//    It points somewhere in the middle of the array
//
// 4. Accessing misaligned data → undefined behavior
//
// TYPICAL SIZES (64-bit system):
//   class Animal { int weight; };              // ~8 bytes + vptr = 16 bytes
//   class Dog : public Animal { string breed; }; // 16 + ~32 = 48 bytes
//
//   ptr[1] advances by 16 bytes
//   But Dog1 starts at 48 bytes offset
//   Massive misalignment!
//
// CORRECT APPROACH:
//   Animal* animals[3] = {
//       new Dog{10, "Beagle"},
//       new Dog{20, "Poodle"},
//       new Dog{15, "Husky"}
//   };
//   animals[1]->speak();  // Correct! Pointer to pointer array
//
// Or use smart pointers:
//   vector<unique_ptr<Animal>> animals;
//   animals.push_back(make_unique<Dog>(10, "Beagle"));
// ============================================================================


// Q18 ANSWER: C) Data misalignment: ptr[1] doesn't point to second dog
//
// EXPLANATION:
// This code demonstrates the array polymorphism pitfall in action.
//
// MEMORY LAYOUT:
//   Dog has: Animal subobject (8 bytes) + string breed (~32 bytes) = ~48 bytes
//   Animal has: int weight (4 bytes) + padding + vptr (8 bytes) = ~16 bytes
//
// Array dogs[3]:
//   Address 0:  Dog{10, "Beagle"}   (48 bytes)
//   Address 48: Dog{20, "Poodle"}   (48 bytes)
//   Address 96: Dog{15, "Husky"}    (48 bytes)
//
// Animal* ptr = dogs:
//   ptr points to address 0 (beginning of dogs array)
//
// ptr[1]:
//   Advances ptr by sizeof(Animal) = 16 bytes
//   Points to address 16
//   But Dog{20, "Poodle"} starts at address 48!
//   Address 16 is IN THE MIDDLE of Dog{10, "Beagle"}
//
// ptr[1].speak():
//   Interprets memory at address 16 as an Animal
//   This is NOT the start of an object
//   Reads garbage data, likely crashes
//
// OUTCOME:
// - Not a compiler error (implicit array-to-pointer conversion is legal)
// - Not a clean virtual dispatch failure
// - Data misalignment leading to undefined behavior
//
// ANSWER: C
// ============================================================================


// Q19 ANSWER: B) Animal* animals[3] = {new Dog{}, new Cat{}, new Bird{}};
//
// EXPLANATION:
// Let's analyze each option:
//
// A) Animal animals[3] = {Dog{}, Cat{}, Bird{}};
//    WRONG - Object slicing!
//    - Array allocates 3 Animal objects
//    - Dog{}, Cat{}, Bird{} are sliced when copied into Animal slots
//    - No polymorphism
//
// B) Animal* animals[3] = {new Dog{}, new Cat{}, new Bird{}};
//    CORRECT!
//    - Array of POINTERS to Animal
//    - Each pointer can point to any derived class
//    - Polymorphism works: animals[i]->speak() dispatches correctly
//    - Must remember to delete: for (auto p : animals) delete p;
//
// C) vector<Animal> animals = {Dog{}, Cat{}, Bird{}};
//    WRONG - Object slicing!
//    - vector stores Animal objects by value
//    - Derived objects are sliced when inserted
//    - No polymorphism
//
// D) Dog* animals[3] = {new Dog{}, new Dog{}, new Dog{}};
//    WRONG - Not polymorphic!
//    - All elements must be Dogs
//    - Cannot store Cats or Birds
//    - Defeats the purpose of polymorphism
//
// E) Both A and C are correct
//    WRONG - Both A and C cause slicing
//
// BEST PRACTICE (Modern C++):
//   vector<unique_ptr<Animal>> animals;
//   animals.push_back(make_unique<Dog>());
//   animals.push_back(make_unique<Cat>());
//   animals.push_back(make_unique<Bird>());
//   // Automatic memory management + polymorphism!
//
// ANSWER: B
// ============================================================================


// Q20 ANSWER: TRUE
//
// EXPLANATION:
// This is exactly why array polymorphism fails.
//
// POINTER ARITHMETIC RULES:
//   T* ptr;
//   ptr + n  →  advances by n * sizeof(T) bytes
//   ptr[n]   →  equivalent to *(ptr + n)
//
// PROBLEM WITH POLYMORPHIC ARRAYS:
//   Dog dogs[3];
//   Animal* ptr = dogs;
//   ptr[1];  // Advances by sizeof(Animal), not sizeof(Dog)!
//
// DETAILED EXAMPLE:
//   class Animal {
//       int weight;      // 4 bytes
//       // padding       // 4 bytes
//       // vptr          // 8 bytes
//   };  // Total: 16 bytes
//
//   class Dog : public Animal {
//       string breed;    // 32 bytes
//   };  // Total: 48 bytes
//
//   Dog dogs[10];
//   Animal* ptr = dogs;
//
//   ptr[0]: Advances by 0 * 16 = 0 bytes    → Points to dogs[0] ✓
//   ptr[1]: Advances by 1 * 16 = 16 bytes   → Points INSIDE dogs[0] ✗
//   ptr[2]: Advances by 2 * 16 = 32 bytes   → Points INSIDE dogs[0] ✗
//   ptr[3]: Advances by 3 * 16 = 48 bytes   → Points to dogs[1] (by accident!) ✗
//
// The pointer arithmetic is "out of sync" with the actual array layout.
//
// ROOT CAUSE:
// - Compiler uses STATIC TYPE for sizeof calculation
// - ptr has static type Animal*
// - sizeof(Animal) is used for arithmetic
// - Actual objects are larger (sizeof(Dog))
//
// SOLUTION:
// - Use array of pointers
// - All pointers are same size (8 bytes)
// - Arithmetic works correctly
// ============================================================================


// ============================================================================
// SECTION 5: CASTING AND RTTI - ANSWERS
// ============================================================================

// Q21 ANSWER: B) dynamic_cast
//
// EXPLANATION:
// C++ provides four cast operators:
//
// 1. static_cast - Compile-time conversion, NO runtime checking
//    - Trust programmer completely
//    - Fast, no overhead
//    - Dangerous for downcasting
//
// 2. dynamic_cast - Runtime type checking (RTTI)
//    - Safe downcasting in polymorphic hierarchies
//    - Returns nullptr if cast invalid (for pointers)
//    - Throws bad_cast if invalid (for references)
//    - Requires virtual methods (RTTI support)
//    - Small runtime overhead (vtable lookup)
//
// 3. const_cast - Add/remove const qualifier
//    - Only affects const-ness
//    - Dangerous: modifying truly const data is undefined behavior
//
// 4. reinterpret_cast - Bitwise reinterpretation
//    - Very dangerous, low-level
//    - No conversions, just reinterprets bits
//    - Use only for systems programming
//
// Example of dynamic_cast:
//   Base* b = getSomeObject();
//   Derived* d = dynamic_cast<Derived*>(b);
//   if (d != nullptr) {
//       // b actually points to a Derived object
//       d->derivedMethod();
//   } else {
//       // b does not point to a Derived object
//   }
//
// ANSWER: B
// ============================================================================


// Q22 ANSWER: FALSE
//
// EXPLANATION:
// dynamic_cast has strict requirements - it only works with POLYMORPHIC types.
//
// REQUIREMENTS:
// 1. The class must have at least ONE virtual method
// 2. This enables RTTI (Runtime Type Information)
// 3. The compiler generates type information in the vtable
//
// EXAMPLE - Won't compile:
//   class Base {
//       // No virtual methods
//   };
//   class Derived : public Base {};
//
//   Base* b = new Derived{};
//   Derived* d = dynamic_cast<Derived*>(b);  // COMPILER ERROR!
//   // Error: 'Base' is not polymorphic
//
// FIXED:
//   class Base {
//   public:
//       virtual ~Base() {}  // Now polymorphic
//   };
//
//   Derived* d = dynamic_cast<Derived*>(b);  // OK!
//
// WHY THE REQUIREMENT?
// - dynamic_cast needs to check the actual object type at runtime
// - Type information is stored in the vtable
// - No virtual methods = no vtable = no type information
//
// WHAT IF YOU NEED CASTING WITHOUT VIRTUAL METHODS?
// - Use static_cast (programmer guarantees correctness)
// - Or redesign to use polymorphism
//
// NOTE: Even ONE virtual method (like virtual destructor) is sufficient.
// ============================================================================


// Q23 ANSWER: B) nullptr
//
// EXPLANATION:
// This demonstrates dynamic_cast failure handling with pointers.
//
// Code analysis:
//   Book* b = new Book{};
//   Text* t = dynamic_cast<Text*>(b);
//
// What happens:
// 1. b points to a Book object (not a Text object)
// 2. dynamic_cast<Text*>(b) attempts to cast to Text*
// 3. Runtime check: "Is the object pointed to by b actually a Text?"
// 4. Answer: NO (it's just a Book)
// 5. Cast fails
// 6. For POINTER casts, failure returns nullptr
//
// Therefore: t == nullptr
//
// IF THE CAST SUCCEEDED:
//   Book* b = new Text{};  // b points to a Text
//   Text* t = dynamic_cast<Text*>(b);
//   // Now t points to the same object as b (the Text)
//
// CONTRAST WITH REFERENCES:
//   Book& br = *b;
//   Text& tr = dynamic_cast<Text&>(br);  // Throws std::bad_cast!
//
// POINTER vs REFERENCE behavior:
// - Pointers: failure → nullptr (can test with if)
// - References: failure → throws bad_cast exception (use try-catch)
//
// WHY THE DIFFERENCE?
// - nullptr is a valid pointer value, can represent failure
// - References cannot be null, must throw exception for failure
//
// ANSWER: B
// ============================================================================


// Q24 ANSWER: A) At least one virtual method in the base class
//
// EXPLANATION:
// dynamic_cast requires the class to be POLYMORPHIC.
//
// POLYMORPHIC CLASS:
// - Has at least one virtual method (any virtual method)
// - Enables RTTI (Runtime Type Information)
// - Compiler generates vtable with type information
//
// Minimum requirement:
//   class Base {
//   public:
//       virtual void dummy() {}  // Just one virtual method
//   };
//
// Or more commonly:
//   class Base {
//   public:
//       virtual ~Base() {}  // Virtual destructor (good practice anyway)
//   };
//
// WHY NOT THE OTHER OPTIONS?
//
// B) Virtual destructor in the base class
//    - Not strictly required (any virtual method works)
//    - But HIGHLY RECOMMENDED for other reasons (memory safety)
//
// C) All methods must be virtual
//    - Not required, just ONE virtual method is enough
//
// D) The class must be abstract
//    - Not required, concrete classes work fine with dynamic_cast
//
// E) No requirements
//    - Wrong, RTTI requires at least one virtual method
//
// TECHNICAL DETAIL:
// The vtable contains a pointer to a type_info object:
//   vtable for Derived:
//   - type_info* → points to type_info for Derived
//   - function pointers for virtual methods
//
// dynamic_cast uses this type_info to check types at runtime.
//
// ANSWER: A
// ============================================================================


// Q25 ANSWER: A) Prints "Cast failed"
//
// EXPLANATION:
// This demonstrates dynamic_cast with REFERENCES and exception handling.
//
// Code analysis:
//   Base b;  // Create a Base object (not Derived)
//   Derived& d = dynamic_cast<Derived&>(b);  // Try to cast to Derived&
//
// What happens:
// 1. b is a Base object (static type: Base, dynamic type: Base)
// 2. dynamic_cast<Derived&> attempts to cast reference
// 3. Runtime check: "Is b actually a Derived object?"
// 4. Answer: NO (it's just a Base)
// 5. Cast fails
// 6. For REFERENCE casts, failure throws std::bad_cast exception
// 7. Exception is caught by catch (std::bad_cast& e)
// 8. Prints "Cast failed"
//
// Output: "Cast failed"
//
// WHY THROW INSTEAD OF RETURNING SOMETHING?
// - References cannot be null
// - No "null reference" to return on failure
// - Exception is the only way to signal failure
//
// CONTRAST WITH POINTERS:
//   Base* bp = &b;
//   Derived* dp = dynamic_cast<Derived*>(bp);
//   // dp == nullptr (no exception)
//
// BEST PRACTICE:
// - Use pointer casts when you can tolerate nullptr
// - Use reference casts when failure is exceptional
//
// EXAMPLE WHERE CAST SUCCEEDS:
//   Derived d;
//   Base& br = d;
//   Derived& dr = dynamic_cast<Derived&>(br);  // Success! No exception
//
// ANSWER: A
// ============================================================================


// ============================================================================
// SECTION 6: VTABLES AND MEMORY LAYOUT - ANSWERS
// ============================================================================

// Q26 ANSWER: C) sizeof(Vec1) == 8 bytes, sizeof(Vec2) == 16 bytes
//
// EXPLANATION:
// Virtual methods change the memory layout of objects.
//
// Vec1 (no virtual methods):
//   class Vec1 {
//       int x, y;  // 2 ints × 4 bytes = 8 bytes
//   };
//   sizeof(Vec1) = 8 bytes
//
// Vec2 (with virtual method):
//   class Vec2 {
//       int x, y;          // 8 bytes
//       virtual int foo(); // Causes vptr to be added
//   };
//   // Hidden vptr field added by compiler (8 bytes on 64-bit)
//   sizeof(Vec2) = 16 bytes
//
// MEMORY LAYOUT:
//   Vec1: [x: 4 bytes][y: 4 bytes]                     = 8 bytes
//   Vec2: [vptr: 8 bytes][x: 4 bytes][y: 4 bytes]      = 16 bytes
//
// THE VPTR (Virtual Pointer):
// - Pointer to the vtable for this class
// - Added automatically by compiler when class has virtual methods
// - Size: 8 bytes on 64-bit systems, 4 bytes on 32-bit
// - Only ONE vptr per object, regardless of number of virtual methods
//
// VTABLE (Virtual Table):
// - One vtable per CLASS (not per object)
// - Contains pointers to all virtual methods
// - Shared by all objects of that class
//
// COST OF VIRTUAL:
// - Memory: +8 bytes per object (for vptr)
// - Performance: Slight overhead for vtable lookup
// - Worth it for polymorphism!
//
// ANSWER: C
// ============================================================================


// Q27 ANSWER: FALSE
//
// EXPLANATION:
// This is a crucial misconception to correct.
//
// VTABLE STORAGE:
// - ONE vtable per CLASS (stored in read-only memory)
// - Shared by ALL objects of that class
// - NOT copied into each object
//
// VPTR STORAGE:
// - ONE vptr per OBJECT
// - Points to the class's vtable
// - This IS in each object
//
// Example:
//   class Animal {
//   public:
//       virtual void speak() {}
//   };
//
//   Animal a1, a2, a3;
//
// Memory layout:
//   ONE vtable for Animal class:
//     [type_info*][&Animal::speak]
//
//   THREE objects with vptrs:
//     a1: [vptr → Animal vtable]
//     a2: [vptr → Animal vtable]  (same vtable!)
//     a3: [vptr → Animal vtable]  (same vtable!)
//
// WHY THIS DESIGN?
// - Efficiency: Vtable can be large, don't duplicate it
// - Space: Only one copy of method pointers needed
// - Speed: Vtable in read-only memory, can be cached
//
// COST BREAKDOWN:
// - Per CLASS: One vtable (N virtual methods × 8 bytes)
// - Per OBJECT: One vptr (8 bytes)
//
// EXAMPLE:
//   class Animal {
//   public:
//       virtual void speak() {}
//       virtual void eat() {}
//       virtual void sleep() {}
//   };
//
//   Per class: One vtable (3 methods × 8 bytes = 24 bytes)
//   Per object: One vptr (8 bytes)
//
//   1000 Animal objects:
//     Total vtable storage: 24 bytes (just one copy)
//     Total vptr storage: 1000 × 8 = 8000 bytes
//
// If each object had its own vtable copy:
//     Wrong approach: 1000 × 24 = 24000 bytes (wasteful!)
//
// ANSWER: FALSE - Objects have vptrs, not vtables
// ============================================================================


// Q28 ANSWER: C) The vtable for that object's class
//
// EXPLANATION:
// The vptr (virtual pointer) is the mechanism that enables polymorphism.
//
// VPTR PURPOSE:
// - Points to the vtable (virtual table)
// - Tells the object which class's virtual methods to use
//
// VTABLE STRUCTURE:
//   vtable for Derived:
//   [0] type_info* (for RTTI)
//   [1] &Derived::method1
//   [2] &Derived::method2
//   [3] &Base::method3 (if not overridden)
//   [4] &Derived::~Derived (destructor)
//
// VIRTUAL DISPATCH PROCESS:
//   Base* bp = new Derived{};
//   bp->virtualMethod();
//
// Steps:
// 1. Follow bp to the object
// 2. Read the vptr from the object
// 3. vptr points to Derived's vtable
// 4. Look up virtualMethod in the vtable
// 5. Find &Derived::virtualMethod
// 6. Call that function
//
// EXAMPLE:
//   class Animal {
//       int weight;
//       // vptr hidden here (added by compiler)
//   public:
//       virtual void speak() { cout << "Animal"; }
//   };
//
//   class Dog : public Animal {
//   public:
//       void speak() override { cout << "Woof"; }
//   };
//
//   Animal a;
//   Dog d;
//
// Memory:
//   a: [vptr → Animal vtable][weight]
//   d: [vptr → Dog vtable][weight (inherited)]
//
// When speak() is called:
//   Animal* ap = &d;
//   ap->speak();
//   // 1. Follow ap to the Dog object
//   // 2. Read vptr from object
//   // 3. vptr points to Dog vtable
//   // 4. Look up speak in Dog vtable
//   // 5. Call Dog::speak
//   // Output: "Woof"
//
// KEY INSIGHT:
// - The vptr's value determines which vtable is used
// - Different objects can have vptrs pointing to different vtables
// - This is how polymorphism works!
//
// ANSWER: C
// ============================================================================


// Q29 ANSWER: C) At runtime, only for virtual methods called through pointers/references
//
// EXPLANATION:
// Virtual dispatch (vtable lookup) has specific conditions for when it occurs.
//
// WHEN VIRTUAL DISPATCH HAPPENS:
// 1. Method must be virtual
// 2. Called through pointer OR reference
// 3. At RUNTIME
//
// WHEN IT DOESN'T HAPPEN:
//
// Case 1: Non-virtual method
//   bp->nonVirtualMethod();  // Static binding, compile-time
//
// Case 2: Called on object directly (not through pointer/reference)
//   Derived d;
//   d.virtualMethod();  // No dispatch! Direct call to Derived::virtualMethod
//   // Compiler knows exact type at compile time
//
// Case 3: Called from constructor/destructor
//   class Base {
//   public:
//       Base() { foo(); }  // Calls Base::foo, not derived version!
//       virtual void foo() {}
//   };
//
// WHY CASE 2 DOESN'T NEED DISPATCH:
//   Derived d;
//   d.virtualMethod();
//
// - Static type of d is Derived
// - Dynamic type of d is Derived
// - Compiler knows both at compile time
// - Can directly call Derived::virtualMethod
// - No vtable lookup needed (optimization)
//
// WHEN DISPATCH IS NECESSARY:
//   Base* bp = getObject();  // Don't know actual type at compile time
//   bp->virtualMethod();     // MUST use vtable lookup
//
// PERFORMANCE IMPLICATIONS:
// - Direct call: Fast (no overhead)
// - Virtual dispatch: Small overhead (one vtable lookup)
//   - Follow vptr
//   - Index into vtable
//   - Follow function pointer
//   - Usually negligible due to caching
//
// ANSWER: C
// ============================================================================


// ============================================================================
// SECTION 7: COPY/MOVE SEMANTICS WITH INHERITANCE - ANSWERS
// ============================================================================

// Q30 ANSWER: TRUE
//
// EXPLANATION:
// When defining a copy constructor for a derived class, you MUST explicitly
// initialize the base class portion.
//
// CORRECT:
//   class Derived : public Base {
//   public:
//       Derived(const Derived& other)
//           : Base{other},  // MUST call base copy constructor
//             derivedField{other.derivedField}
//       {}
//   };
//
// WRONG:
//   class Derived : public Base {
//   public:
//       Derived(const Derived& other)
//           : derivedField{other.derivedField}  // Missing base initialization!
//       {}
//   };
//   // Compiler tries to call Base's DEFAULT constructor
//   // If Base has no default constructor → COMPILE ERROR
//   // If Base has default constructor → base portion is default-initialized
//
// WHY NECESSARY?
// - Derived object contains a Base subobject
// - Derived constructor must initialize the Base subobject
// - If not specified, compiler calls Base's default constructor
// - To copy the base portion, must explicitly call Base's copy constructor
//
// AUTOMATIC CONVERSION:
//   Base{other}
//   // 'other' is type Derived&
//   // Derived IS-A Base
//   // Derived& binds to const Base&
//   // Calls Base::Base(const Base&)
//   // Only Base portion of 'other' is copied
//
// SAME FOR MOVE CONSTRUCTOR:
//   Derived(Derived&& other)
//       : Base{std::move(other)},  // Move base portion
//         derivedField{std::move(other.derivedField)}
//   {}
//
// ANSWER: TRUE
// ============================================================================


// Q31 ANSWER: D) Compiler generates Text copy constructor that calls Book's copy ctor
//
// EXPLANATION:
// When no copy constructor is defined, the compiler generates one automatically.
//
// COMPILER-GENERATED COPY CONSTRUCTOR:
//   Text(const Text& other)
//       : Book{other},                   // Calls Book's copy constructor
//         topic{other.topic}             // Copies topic field
//   {}
//
// Step-by-step for Text t2 = t1:
// 1. Compiler looks for Text::Text(const Text&)
// 2. Not found, so compiler generates one
// 3. Generated constructor:
//    a) Calls base class copy constructor: Book{other}
//    b) Copies each field: topic{other.topic}
//
// WHY OPTION D, NOT C?
// - Option C says topic is "default-initialized" (wrong)
// - Compiler-generated copy constructor COPIES all fields
// - topic{other.topic} copies the topic string
//
// WHEN DEFAULT-INITIALIZATION HAPPENS:
//   Text(const Text& other) : Book{other} {
//       // topic is default-initialized if not in MIL
//   }
//   // But compiler-generated version puts topic in MIL
//
// IMPORTANT DISTINCTION:
// - User-defined copy ctor: You control initialization
// - Compiler-generated: Automatically copies base + all fields
//
// WHEN COMPILER WON'T GENERATE:
// - If you define ANY constructor (except copy/move)
// - If base class has deleted copy constructor
// - If any field has deleted copy constructor
//
// EXAMPLE WHERE YOU MUST DEFINE:
//   class Text : public Book {
//       int* data;
//   public:
//       Text(const Text& other)
//           : Book{other},
//             data{new int{*other.data}}  // Deep copy needed
//       {}
//   };
//
// ANSWER: D
// ============================================================================


// Q32 ANSWER: D) Both B and C are correct
//
// EXPLANATION:
// When implementing a move constructor, you must cast the parameter to an
// rvalue when passing to the base class.
//
// THE PROBLEM:
//   class Derived : public Base {
//   public:
//       Derived(Derived&& other)
//           : Base{other}  // WRONG!
//       {}
//   };
//
// Why wrong?
// - other is an rvalue reference (Derived&&)
// - But the NAME 'other' is an lvalue!
// - Base{other} calls Base's COPY constructor, not move constructor
//
// CORRECT SOLUTIONS:
//
// Option B: Using std::move
//   Derived(Derived&& other)
//       : Base{std::move(other)}  // Converts to rvalue
//   {}
//
// Option C: Using static_cast
//   Derived(Derived&& other)
//       : Base{static_cast<Base&&>(other)}  // Cast to Base rvalue ref
//   {}
//
// Both are correct! std::move is just a convenient wrapper for static_cast.
//
// WHAT std::move DOES:
//   template<typename T>
//   T&& move(T& x) {
//       return static_cast<T&&>(x);
//   }
//
// COMPLETE MOVE CONSTRUCTOR:
//   class Text : public Book {
//       string topic;
//   public:
//       Text(Text&& other)
//           : Book{std::move(other)},           // Move base
//             topic{std::move(other.topic)}     // Move topic
//       {}
//   };
//
// KEY INSIGHT:
// - Rvalue reference parameter (Derived&&) is itself an lvalue
// - Must use std::move or cast to treat it as rvalue
// - This enables move semantics instead of copy semantics
//
// REMEMBER:
// - std::move doesn't move anything!
// - It just casts to rvalue reference
// - The actual move happens when move constructor/assignment runs
//
// ANSWER: D
// ============================================================================


// Q33 ANSWER: C) Partial assignment: only A's fields are assigned, B's fields ignored
//
// EXPLANATION:
// This demonstrates the "polymorphic assignment problem."
//
// Code analysis:
//   B b1;
//   A* a = new B{};
//   *a = b1;  // Calls A::operator=, not B::operator=
//
// What happens:
// 1. *a dereferences to an A& (static type)
// 2. Compiler looks for A::operator=(const A&)
// 3. Found: virtual A& operator=(const A& other)
// 4. Virtual dispatch → Should call B::operator=, right?
// 5. BUT B has no operator= defined!
// 6. So A::operator= is used
// 7. A::operator= only knows about A's fields
// 8. Only 'data' is copied, 'moreData' is unchanged
//
// MEMORY STATE:
//   Before *a = b1:
//     *a: [data → heap1][moreData → heap2]  (B object)
//     b1: [data → heap3][moreData → heap4]  (B object)
//
//   After *a = b1:
//     *a: [data → heap5 (copy of heap3)][moreData → heap2 (unchanged!)]
//
// PROBLEMS:
// - Partial assignment: Only A's portion copied
// - B's fields (moreData) not assigned
// - Object is in inconsistent state
//
// THE FIX - Define B::operator=:
//   class B : public A {
//   public:
//       B& operator=(const B& other) {
//           if (this == &other) return *this;
//           A::operator=(other);  // Assign base portion
//           delete moreData;
//           moreData = new int{*other.moreData};
//           return *this;
//       }
//   };
//
// BETTER FIX - Use virtual assignment correctly:
//   class B : public A {
//   public:
//       A& operator=(const A& other) override {
//           const B& b = dynamic_cast<const B&>(other);
//           A::operator=(other);
//           delete moreData;
//           moreData = new int{*b.moreData};
//           return *this;
//       }
//   };
//
// BEST PRACTICE:
// - Avoid polymorphic assignment through base pointers
// - Prefer working with concrete types
// - Or use virtual clone() method instead
//
// ANSWER: C
// ============================================================================


// ============================================================================
// SECTION 8: PURE VIRTUAL AND ABSTRACT CLASSES - ANSWERS
// ============================================================================

// Q34 ANSWER: TRUE
//
// EXPLANATION:
// A class with at least one pure virtual method is ABSTRACT and cannot be
// instantiated.
//
// PURE VIRTUAL METHOD:
//   class Shape {
//   public:
//       virtual void draw() = 0;  // Pure virtual
//   };
//
// ATTEMPTING TO INSTANTIATE:
//   Shape s;  // COMPILER ERROR!
//   // Error: cannot declare variable 's' to be of abstract type 'Shape'
//
// WHY?
// - Pure virtual method has no implementation (in the abstract class)
// - Creating an object would mean calling an unimplemented method
// - Compiler prevents this at compile time
//
// WHAT YOU CAN DO:
//   Shape* sp;           // OK - pointer to abstract class
//   Shape& sr = derived; // OK - reference to abstract class
//   Shape* sp = new Derived{};  // OK - pointer to concrete derived class
//
// TO MAKE CONCRETE:
//   class Circle : public Shape {
//   public:
//       void draw() override { /* implementation */ }
//   };
//
//   Circle c;  // OK - Circle is concrete
//
// PARTIAL IMPLEMENTATION:
//   class Ellipse : public Shape {
//       // Doesn't implement draw()
//   };
//
//   Ellipse e;  // COMPILER ERROR!
//   // Ellipse is still abstract
//
// USE CASES FOR ABSTRACT CLASSES:
// - Define interface contracts
// - Prevent instantiation of base classes
// - Force derived classes to implement specific methods
//
// EVEN PURE VIRTUAL CAN HAVE IMPLEMENTATION:
//   class Shape {
//   public:
//       virtual void draw() = 0;  // Pure virtual
//   };
//
//   void Shape::draw() {  // Provide implementation
//       cout << "Default drawing";
//   }
//
//   class Circle : public Shape {
//   public:
//       void draw() override {
//           Shape::draw();  // Can call base implementation
//           cout << " a circle";
//       }
//   };
//
// But Shape is still abstract - cannot instantiate.
//
// ANSWER: TRUE
// ============================================================================


// Q35 ANSWER: B) Compiler error: Circle is still abstract
//
// EXPLANATION:
// Circle inherits the pure virtual method draw() but doesn't implement it,
// so Circle remains abstract.
//
// INHERITANCE OF PURE VIRTUAL:
//   class Shape {
//   public:
//       virtual void draw() = 0;  // Pure virtual
//   };
//
//   class Circle : public Shape {
//       // No draw() implementation
//   };
//
// Circle's status:
// - Inherits draw() = 0 from Shape
// - Does not override draw()
// - Still has a pure virtual method
// - Therefore: Circle is ABSTRACT
//
// Attempting to instantiate:
//   Circle c{5.0};  // COMPILER ERROR!
//   // Error: cannot declare variable 'c' to be of abstract type 'Circle'
//   // Note: because the following virtual functions are pure within 'Circle':
//   //     virtual void Shape::draw()
//
// TO FIX:
//   class Circle : public Shape {
//       double radius;
//   public:
//       Circle(double r) : radius{r} {}
//       void draw() override {  // Provide implementation
//           cout << "Drawing circle with radius " << radius << endl;
//       }
//   };
//
//   Circle c{5.0};  // NOW OK
//
// TRANSITIVITY OF ABSTRACTNESS:
// - If base is abstract, derived is abstract UNLESS it implements all pure
//   virtual methods
//
// MULTI-LEVEL EXAMPLE:
//   class Shape { virtual void draw() = 0; };
//   class Ellipse : public Shape {};  // Still abstract
//   class Circle : public Ellipse {};  // Still abstract!
//
//   // Circle must implement draw() even though it's in Shape
//
// ANSWER: B
// ============================================================================


// Q36 ANSWER: TRUE
//
// EXPLANATION:
// Pure virtual methods CAN have implementations, and derived classes can
// explicitly call them.
//
// PROVIDING IMPLEMENTATION:
//   class Animal {
//   public:
//       virtual void speak() = 0;  // Pure virtual
//   };
//
//   void Animal::speak() {  // Implementation
//       cout << "Some animal sound";
//   }
//
// CALLING FROM DERIVED CLASS:
//   class Dog : public Animal {
//   public:
//       void speak() override {
//           Animal::speak();  // Explicitly call base implementation
//           cout << " - Woof!";
//       }
//   };
//
// Usage:
//   Dog d;
//   d.speak();
//   // Output: "Some animal sound - Woof!"
//
// WHY IS THIS USEFUL?
// - Provide default behavior that derived classes can use
// - Share common code between derived classes
// - Derived classes can extend rather than completely replace
//
// IMPORTANT:
// - Class is STILL abstract (cannot instantiate Animal)
// - Derived classes MUST override the pure virtual method
// - But they can call base implementation if they want
//
// CANNOT CALL THROUGH BASE POINTER:
//   Animal* ap = new Dog{};
//   ap->speak();  // Calls Dog::speak (virtual dispatch)
//   // Cannot call Animal::speak unless explicitly in Dog::speak
//
// PURE VIRTUAL DESTRUCTOR EXAMPLE:
//   class Base {
//   public:
//       virtual ~Base() = 0;  // Pure virtual
//   };
//
//   Base::~Base() {}  // MUST provide implementation!
//   // Derived destructors automatically call base destructor
//
// ANSWER: TRUE
// ============================================================================


// ============================================================================
// SECTION 9: ADVANCED SCENARIOS - ANSWERS
// ============================================================================

// Q37 ANSWER: B) "Base::foo"
//
// EXPLANATION:
// This is a subtle but important point: virtual dispatch does NOT work in
// constructors!
//
// Why it prints "Base::foo":
//
// 1. Derived d; creates a Derived object
// 2. Construction order:
//    a. Allocate memory
//    b. Base constructor runs first
//
// 3. Inside Base::Base():
//    Base() { foo(); }
//
// 4. At this point:
//    - Base portion is being constructed
//    - Derived portion DOES NOT EXIST YET
//    - Object is temporarily a Base object
//    - vptr points to Base's vtable
//
// 5. foo() is called:
//    - Virtual dispatch uses vptr
//    - vptr points to Base vtable
//    - Base::foo() is called
//    - Prints "Base::foo"
//
// 6. After Base constructor finishes:
//    - vptr is updated to Derived's vtable
//    - Derived constructor body runs
//
// WHY THIS BEHAVIOR?
// - Safety: Calling Derived::foo() before Derived is constructed is dangerous
// - Derived::foo() might use Derived's fields (not initialized yet!)
//
// DANGEROUS IF IT WORKED DIFFERENTLY:
//   class Derived : public Base {
//       string name;
//   public:
//       Derived() : Base{}, name{"Object"} {}
//       void foo() override {
//           cout << name.length();  // name not initialized yet!
//       }
//   };
//
// SAME IN DESTRUCTOR:
//   class Base {
//   public:
//       virtual ~Base() { foo(); }  // Calls Base::foo, not Derived::foo
//       virtual void foo() {}
//   };
//
// During destruction:
// - Derived destructor runs, destroys Derived fields
// - vptr updated to Base's vtable
// - Base destructor runs
// - foo() call uses Base's vtable
//
// ANSWER: B
// ============================================================================


// Q38 ANSWER: B) Points to a valid B object
//
// EXPLANATION:
// This demonstrates COVARIANT RETURN TYPES - an advanced C++ feature.
//
// COVARIANT RETURN TYPES:
// - Derived class can override virtual method with MORE SPECIFIC return type
// - Return type must be pointer/reference to a derived class
//
// In the code:
//   class A {
//   public:
//       virtual A* clone() { return new A{x}; }
//   };
//
//   class B : public A {
//   public:
//       B* clone() override { return new B{*this}; }
//       // Return type is B*, not A*
//       // This is ALLOWED (covariant return type)
//   };
//
// What happens:
//   A* a = new B{1, 2};
//   A* copy = a->clone();
//
// 1. a points to a B object
// 2. a->clone() uses virtual dispatch
// 3. B::clone() is called
// 4. Returns new B{*this} → creates a B object
// 5. Returned as B*, implicitly converted to A* (upcasting)
// 6. copy points to a B object
//
// 7. dynamic_cast<B*>(copy):
//    - copy actually points to a B object
//    - Cast succeeds
//    - b points to the same B object as copy
//
// WHY COVARIANT RETURN TYPES?
//   A* a = new B{1, 2};
//   B* b = a->clone();  // Would fail without covariant returns
//   // clone() returns A*, cannot assign to B*
//
//   // With covariant returns:
//   B* b = a->clone();  // Works if a points to B!
//   // Return type is actually B*, not just A*
//
// RULES FOR COVARIANCE:
// - Must be pointer or reference
// - Return type in derived must be derived from return type in base
// - Not allowed: value types (cannot return B if base returns A)
//
// ANSWER: B
// ============================================================================


// Q39 ANSWER: TRUE
//
// EXPLANATION:
// Exception slicing is a real and dangerous problem.
//
// THE PROBLEM:
//   class BaseException {};
//   class DerivedException : public BaseException {
//       string details;
//   public:
//       DerivedException(string d) : details{d} {}
//   };
//
//   try {
//       throw DerivedException{"Important info"};
//   }
//   catch (BaseException e) {  // Catching by VALUE - WRONG!
//       throw e;  // Re-throwing - throws SLICED exception!
//   }
//
// What happens:
// 1. DerivedException is thrown
// 2. catch (BaseException e) catches by value
// 3. DerivedException is SLICED into BaseException
// 4. 'details' field is lost
// 5. throw e; throws a BaseException, not DerivedException
//
// CORRECT:
//   catch (BaseException& e) {  // Catch by REFERENCE
//       throw;  // Bare throw - re-throws ORIGINAL exception
//   }
//
// or:
//   catch (BaseException& e) {
//       throw e;  // Also OK with reference - no slicing
//   }
//
// DIFFERENCE BETWEEN throw; and throw e;
//
// throw; (bare throw):
// - Re-throws the ORIGINAL exception object
// - Preserves dynamic type
// - No slicing
// - Can only be used inside catch block
//
// throw e; (when e is caught by value):
// - Throws a COPY of e
// - Uses static type of e
// - Causes slicing if e was caught by value
//
// throw e; (when e is caught by reference):
// - Throws a copy of the actual exception
// - Preserves dynamic type
// - No slicing
//
// BEST PRACTICE:
// - ALWAYS catch exceptions by reference: catch (Exception& e)
// - Use bare throw; to re-throw: just throw;
//
// WHY CATCH BY REFERENCE?
// - Avoids slicing
// - Avoids copying (efficiency)
// - Preserves polymorphic behavior
//
// ANSWER: TRUE
// ============================================================================


// Q40 ANSWER: B) 1 (true), because only x values are compared
//
// EXPLANATION:
// This demonstrates how friend operators work with inheritance.
//
// Code analysis:
//   class Base {
//   protected:
//       int x;
//   public:
//       friend bool operator==(const Base& a, const Base& b) {
//           return a.x == b.x;
//       }
//   };
//
//   class Derived : public Base {
//       int y;
//   };
//
//   Derived d1{1, 2};  // x=1, y=2
//   Derived d2{1, 3};  // x=1, y=3
//   d1 == d2;
//
// What happens:
// 1. Compiler looks for operator==(Derived, Derived)
// 2. Not found in Derived class
// 3. Looks in Base class
// 4. Finds: friend bool operator==(const Base&, const Base&)
// 5. Derived IS-A Base, so Derived& can bind to const Base&
// 6. operator== is called with d1 and d2
// 7. Inside operator==:
//    - Compares a.x and b.x
//    - Both have x=1
//    - Returns true (y values are IGNORED)
// 8. Output: 1 (true)
//
// WHY y IS IGNORED:
// - operator== is defined in Base
// - It only knows about Base's fields (x)
// - Even though a and b are actually Derived objects, they're treated as Base
// - No access to y (it's in Derived, not Base)
//
// THIS IS A DESIGN FLAW:
// - Two Derived objects with different y values compare equal
// - Violates principle of least astonishment
//
// THE FIX - Define operator== in Derived:
//   class Derived : public Base {
//       int y;
//   public:
//       friend bool operator==(const Derived& a, const Derived& b) {
//           return static_cast<const Base&>(a) == static_cast<const Base&>(b)
//               && a.y == b.y;
//       }
//   };
//
// Now:
//   d1 == d2  // false (y values differ)
//
// KEY LESSON:
// - Inherited friend operators only see base class fields
// - Define comparison operators in derived classes for correct behavior
// - Use static_cast to call base comparison, then add derived fields
//
// ANSWER: B
// ============================================================================


// ============================================================================
// END OF ANSWER KEY
// ============================================================================
//
// KEY TAKEAWAYS:
//
// 1. Object Slicing:
//    - Only with direct object assignment, not pointers/references
//    - Loses derived fields and polymorphic behavior
//
// 2. Virtual Methods:
//    - Dynamic type determines method (runtime)
//    - Non-virtual uses static type (compile-time)
//    - Virtual destructors essential for polymorphism
//
// 3. Polymorphic Arrays:
//    - Never use array of objects polymorphically
//    - Use array of pointers
//    - Pointer arithmetic fails with object arrays
//
// 4. Casting:
//    - dynamic_cast for safe downcasting (requires virtual methods)
//    - Returns nullptr for pointers, throws for references
//    - static_cast trusts programmer
//
// 5. Vtables:
//    - One vtable per class, one vptr per object
//    - Contains pointers to virtual methods
//    - Enables runtime polymorphism
//
// 6. Copy/Move with Inheritance:
//    - Must call base class copy/move constructor
//    - Use std::move for move semantics
//    - Compiler-generated versions do this automatically
//
// 7. Pure Virtual:
//    - Makes class abstract
//    - Can have implementation
//    - Derived must implement to become concrete
//
// 8. Advanced:
//    - Virtual doesn't work in constructors/destructors
//    - Catch exceptions by reference to avoid slicing
//    - Covariant return types allow more specific returns
//
// ============================================================================

int main() {
    cout << "CS246 Theory Questions - Complete Answer Key" << endl;
    cout << "See detailed explanations above" << endl;
    return 0;
}
