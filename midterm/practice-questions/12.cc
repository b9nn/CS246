#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

// which of the following are correct and why?
// soln: overloading.cc

struct vec {
 int x, y;
};

// hint: consider
vec v{2, 3};
vec w = 3 * v; 

vec operator*(const int k, const vec& v) {
    return vec{k * v.x, k * v.y};
}

void operator*(const int k, vec& v) {
    v.x *= k;
    v.y *= k;
}

