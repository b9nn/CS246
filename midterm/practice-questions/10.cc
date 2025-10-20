#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

// implement the following:
// soln: overloading.cc

struct vec {
 int x, y;
};
vec x{1, 2};
vec y{3, 4};
vec z = x + y; // We want the plus sign to do addition
vec w = 2 * x; // We want multiplication to work as expected
vec v = x * 2;

/*
Implement input (>>) and output (<<) stream operators for the following Grade struct so that:

The << operator outputs the grade followed by a percent sign (e.g., 85%).

The >> operator reads an integer value into the grade and clamps it between 0 and 100 (values below 0 become 0, and values above 100 become 100).

Both operators should work with any stream (e.g., std::cin, std::cout, and file streams).

*/

struct Grade {
    int n;
};

// define operator<< here

// define operator>> here
