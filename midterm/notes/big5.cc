#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

// class methods can be written in either the interface or the implementation, however it is advised that you use the implementation file
// for better style

// BENEFITS OF DEFINING CTORS
//  - bound checking
//  - overloading
//  - default parameters (instead of grabage values)

// USE AN MIL
// the copy ctor and the move ctor both just use the mil
// te copy ctor is identical
// the move ctor is also identical except we set all of others fields to 0 or null

// the copy-assn ctor is also very similar
// check for self copy (this != &other) // compare adresses since this is a ptr
// if not then assign, else return a dereferenced version of this

// move assn operator requires a swap and the return of the dereferenced this again
