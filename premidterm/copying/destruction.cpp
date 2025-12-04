/*
DESTRUCTORS (dtors)

- called when an object is destroyed
    (stacks pop, of heaps are freed)

steps
    - dtor body runs
    - dtors for fields
    - space is reallocated
*/

// dtor comes by default but is shallow (just like copy ctor)

struct Node{
    int data;
    Node *next;
};

Node *n = new Node{1,new Node{2, new Node{3, nullptr}}};

delete n; // calls dtor, but only delets the 1, memory gets leaked!

// we need a recursive definition --> define your own


struct Node{
    int data;
    Node *next;
    ~Node() {delete next;} // recursively calls destructor on next node until nullptr
};

// it is valid to call delete on nullptr