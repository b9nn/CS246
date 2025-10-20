#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


// explain wich work and which dont and why
// soln: array-heap.cc

struct Node {
    int data;
    Node *next;
};

Node getMeAMode(int x) {
    Node n{x, nullptr};
    return n;
}

Node* getMeANodePtr(int x) {
    Node n{x, nullptr};
    return n;
}

Node* getMeANodePtr(int x) {
    Node *p = new Node{x, nullptr};
    return p;
}

Node& getMeANodeRef(int x) {
    Node n{x, nullptr};
    return n; // does this exist in the heap?
}
