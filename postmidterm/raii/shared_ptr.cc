// a unique pointer has the limitation that u can only have one unique_ptr to one chunck of heap allocated memory

#include <memory>

std::shared_ptr<T>

// shared ownership, multiple shared pointers can poin to the same memory
// maintains a reference count ot T
// T's dtor runs when it loses all shared pointers! like unique pointer but they all have to go

int main() {
    auto p1 = std::make_shared<MyClass>();
    if(...) {
        auto p2 = p1; // works! 2 pointers to myclass
    }
    // after the conditional block p2 is popped so we only have 1 ref to the myclass pointer
} 
// p1 gets popped so 0 references to myclass exist so myclass dtor runs!
