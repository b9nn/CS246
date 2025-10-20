#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;



struct vec {
    int x, y;
    vec operator*(int k) const {
        return vec{x * k, y * k};
    }
};

// which, if any, of the following work>
// soln: bottom of overloading.cc
v * 3; 
3 * v;   
