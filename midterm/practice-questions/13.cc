#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;


// can the compiler tell the difference between the following overloads?

struct vec {
    int x, y;
};

// 1️⃣ int * vec
vec operator*(int k, const vec& v) {
    return vec{k * v.x, k * v.y};
}

// 2️⃣ vec * int
vec operator*(const vec& v, int k) {
    return vec{v.x * k, v.y * k};
}
