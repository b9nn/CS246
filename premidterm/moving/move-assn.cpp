#include <utilities>
struct Node{
    int data;
    Node *next;
    Node& operator=(Node&& other){
        using std :: swap;
        swap(data, other.data);
        swap(next, other.next);
        return *this;
    } // ~Node() runs on other, deleting our old memory
};


/*
if no move ctor is defined, the compiler uses the copy ctor by default (waste of resources)

~~~ the rule of 5 ~~~
if you need to make or define, any of:
    - copy ctor
    - copy-assn operator
    - move ctor
    - move-assn operator
    - dtor

you should define all of them explicitly --> effective memory managment

*/