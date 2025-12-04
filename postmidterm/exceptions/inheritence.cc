#include <stdexcept>
using namespace std;

class exn {};
class specialexn : public exn {};

try {exn;}
catch {exn e} {
    throw e; // if e is a SpecialExn then it gets sliced into an exn since throw e calls ctor
    throw; // no slicing as it rethrows e
}


// good idea: throw by value and cacth by ref

try {}

catch (exn &e) {
    throw e; // no slicing occurs
}

// to catch all erros
try{}
catch(...) {} // catches ALL exns