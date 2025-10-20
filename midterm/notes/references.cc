// getline(cin, line); and cin >> x, are actually using references

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


// A REFERENCE IS NOT AN OBJECT IN MEMORY

int main() {
    int x = 5;
    int& z = x; // z is an LVALUE reference to x
    // z and x are now bound to eachother, any changes that happen to ether will effect both

    // LVALUE = something that has concrete memory, either stack or heap
    // RVLAUE = something that doesnt have memeory, func(5) for example, gets lost after called

    // note that there is no difference between the following:
    int& x = z;
    int &x = z;

    // === LIMITATIONS ===

    // cannot leave a ref unitialized
    int& y; // error!

    // cannot assign ref to an rvalue
    int& z = 5; // error!

    // can only be assigned to variables (both are errors)
    int &ref = x + z;
    int& ref = myFunc();

    // pointers + references
    int*& ref = x; // this is allowed, we are referencing an int pointer
    int&* myRef = num; // this is not allowed however, since references may not exist in memory so we cannot define a POINTER TO A REFERENCE.

    // cannot create a ref tp a ref
    int&& r = x; // this is becuase a ref "copies the memory" of the object it is referencing, and since the reference itself does not have memory, you cannot copy it

    // cannot create an array of references
    int& myarray = {x, y, z};
}


