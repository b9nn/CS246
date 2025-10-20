// when defining default params, if one is defined, then all the parameters following that must also have default values

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


void foo(int a, int b = 2, int c = 3) { // not
    cout << a + b + c << endl;
}

foo(1, 5, 10); // prints 16
foo(2, 5); // prints 10
foo(1); // prints 6

// invalid example of default params
void dParams(int a = 4, int b) {
    cout << "hi" << endl;
}

// 4 ways to pass paramas
//  - shallow copy
//  - pointer
//  - reference
//  - const reference (the fastest)