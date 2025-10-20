#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

// provide declarations for all functions in interface files
// provide function definitions (body) in the implementation file

// when defining your interface file, make sure to include export

export module vec

export struct vec{
    int x,y;
}

export vec operator+{const vec v1, const vec v2};

// you need 3 different types of export statments
//  - for functions
//  - for structs
//  - for the whole module


// main functions need:
import vec; // import the MODULE

// implementation files need
module vec; // just the name of the module so the compiler knows


