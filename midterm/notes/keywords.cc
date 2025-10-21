// interface

export module vec;

export class vec;

export istream& operator<<()


//impl
module vec;

// client
import module vec;

// === CONVERSION ===

// consider the following:

struct Node {
    int data;
    Node *next;

    Node(int n, Node* next = nullptr):
        data{n}, next{next}{}  
};

void f(Node n){
    // do something with n
}

f(Node{4});
f(4); // works as it gets implicity converted into a node
// do we really want that, probably not its super confusing

// use the "explicit" keyword to stop this implicit coversion

struct Node {
    int data;
    Node *next;
    explicit Node(int d, Node* n = nullptr) :
        data{d}, next{n}{}
};

f(Node{4}); // works
f(4); // wont compiler no more implicit construction

// === CONST OBJECTS ===
const Student ben{1,2,3};

cout << ben.grade() << endl; // since ben is a const, wont run
// CANT RUN METHOD ON OCNST OBJECTS since compiler doesnt know if that method with modify the object

// the solution is to provided a const method, they work with comst objetcs sice they are 
// guaranteed to not mutate the object they act on

// witin a const method we can still mutate certain fileds with the mutate keyword

struct vec {
    int x, y;
    mutable int calls = 0;

    int getX() const {
        calls++; // can mutate within a const method since calls is mutatble 
        return x;
    }
};


// ==== GLOBAL CLASS FIELDS ===
inline static int calls = 0; // initialies a global field that all classes have edit perms of
// only static fields can acsess said methods!

struct student {
    int grade = 0;
    inline static int global = 0;
    int getGrade() const {
        global++; // can mutate even tho its a const method
        return grade;
    }
};

// const methods can mutate inline static (or global) class fields

// static method exists, and can ONLY acsess static fields. however inline static fields can be acsess but any method
