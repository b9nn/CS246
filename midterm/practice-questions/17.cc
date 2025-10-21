#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

// write big 5 for the node class and use deep copies
// soln: big5impl.cc

struct Node {
    int data;
    Node *next;

    Node(int n, Node* follow): // ctor already dunno
        data{n}, next{follow}{}
    }

    // implement it here
};

