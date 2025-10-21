#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

// no method for realloc, must be manually copied
// calls to new must be paired with thier respective delete, same for calls to new[] and delete []

// explain the following:
struct Node {
    int data;
    Node *next;
};

Node getMeAMode(int x) {
    Node n{x, nullptr};
    return n; // works returns a shallow copy of a node, no heap allocation tho
}

Node* getMeANodePtr(int x) {
    Node n{x, nullptr};
    return n; // not returning a pointer to anything, runtime error
}

Node* getMeANodePtr(int x) {
    Node *p = new Node{x, nullptr};
    return p; // proper impl return a heap allocated node but make sure to delete
}

Node& getMeANodeRef(int x) {
    Node n{x, nullptr};
    return n;
    // does not work, returning n, but n is popped off with its stack so we get a referencing pointing to garbage memory, this is also sometimes called a dangling reference
}


struct vec {
 int x, y;
 vec(int x, int y): x{x}, y{y} {}
}; // Note that there is no default constructor

// why are these errors?
vec *vp = new vec[15];
vec sArraray[10];

// when you create an array of objects te default ctor is called on each of them but because there is no default ctor in this instance
// since we definied out own ctor (replaces default c++ is not constructing anything) --> error
// WE DONT SPECIFY THE X AND Y WHEN INITIALIZING

// solutions: add a default ctor (a ctor wiht no parameters)

struct vec {
    int x, y;
    //...

    vec():
        x{0}, y{0}{}
};

// or 

vec sArray[3]= {{0,1}, {1,2}, {2, 3}};

// init as an array of vec pointers (no ctor for pointers then construct indexes)

/*
vec **vp = new vec *[15];
Pointers are primitve classes (not objects) and thus don't need constructors. After declaring an array of
pointers, we can initialize them one-by-one.
vp[0] = new vec{0, 1};
vp[1] = new vec{2, 3}; ...
However, when we are done using this array, we need to manually free all the memory, since it is
allocated in the heap.
for (int i = 0; i < 15; ++i) delete vp[i];
delete[] vp;


*/