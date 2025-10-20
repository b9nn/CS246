#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

// whats wrong?

struct vec {
    int x, y;
};

vec operator+(const vec& v) {
    return vec{x + v.x, y + v.y};
}

// implement correct version:
