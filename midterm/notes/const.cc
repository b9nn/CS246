#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

const int MAX = 1000; // any changes (or attempts i should say) will result in a runtime error

struct Node{
    int data;
    Node *next;
};

const Node n = {5, nullptr}; // any changes to 5 or NULLPTR will result in a compiltion error
