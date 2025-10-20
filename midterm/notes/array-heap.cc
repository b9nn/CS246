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

