// which of the following are valid

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

// explain why for each! soln: ref.cc
int main() {
    int x = 5;
    int& z = x;

    int& x = z;
    int &x = z;

    int& y;
    int& z = 5;
    int &ref = x + z;
    int& ref = myFunc();

    int*& ref = x;
    int&* myRef = num;

    int&& r = x;

    int& myarray = {x, y, z};
}
