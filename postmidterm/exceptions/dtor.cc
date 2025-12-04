/*
if new fails --> throws std::badalloc
NEVER THROW IN A DTOR

example
*/

class node {
    ~Node() {throw SomeExn{};} // BAD
};

/*
dtor throws std::terminate (a special exception)
throwing dtor causes 2 active unhandled exns as once
program immediately aborts 

*/