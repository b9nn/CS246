#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

// most basic example - the >> operator
int main() {
    int x = 5;
    x >> 3; //compiler recognizes this as BITSHIFT bc of the int on the left side
    cin >> x; // compiler recognizes this as the GETFROM operator bc a cin is to the left
}


// you cna overload the same fn name so long as they take diff # of args, or have diff return type
int negate(int x) {
    return -x;
}

bool negate(bool x) {
    return !x;
}

// compiler can tell the difference at compile time wiht the above functions!

struct vec {
 int x, y;
};

vec x{1, 2};
vec y{3, 4};
vec z = x + y; // We want the plus sign to do addition
vec w = 2 * x; // We want multiplication to work as expected
vec v = x * 2;

vec operator+(const vec& v1, const vec& v2) {
  return vec{v1.x + v2.x, v1.y + v2.y};
}

// this only works if it's a member function! you're acsessing this, but you can only use that for member functions of a class
vec operator+(const vec& v) {
    return vec{x + v.x, y + v.y};
}

vec operator*(const int k, const vec& v) {
    return vec{k * v.x, k * v.y};
}

void operator*(const int k, vec& v) {
    v.x *= k;
    v.y *= k;
}

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

istream& operator>>(istream& in, Grade& curr) { // NEITHER PARAM CAN BE CONST
    // could modify fail bit so obv not const 
    in >> curr.n;
    if (curr.n < 0) {
        curr.n = 0;
    }
    else if (curr.n > 100){  // cannot use n, must still use ucrr.n
        curr.n = 100;
    }
    return in;
}

ostream& operator<<(ostream& out, Grade& curr) {
    out << curr.n << "%" << endl;
    return out;
}

// soln to 14.cc
// first works second does not