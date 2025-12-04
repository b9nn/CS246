#include <stdexcept>
using namespace std;

class SomeExnA {};
class SomeExnB {};

try {
    // for some erorr
}

catch (SomeExnA e) {
    // recovery

    throw SomeExnB{}; // valid code

    // or
    throw; // returns THE CAUGHT ERROR, IN THIS CASE E (NO CTOR CALLED)

    throw e; // throws a NEW ExnA (recalls ctor)
}
