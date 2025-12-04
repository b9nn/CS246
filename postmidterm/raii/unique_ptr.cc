#include <memory>

std::unique_ptr<T> // holds a T*

// only allows one unique pointer per type
// use it like any other pointer
// has a dtor to free T

void foo() {
    myclass mc;
    std::unique_ptr<myclass> p = std::make_unique<myclass>(); // allocates on the heap
}

// sample-impl
template <typename t> class unique_ptr {
    t* ptr;
    public:
    unique_ptr(t* p): ptr{p}{}
    ~unique_ptr() {delete ptr}
    unique_ptr(const unique_ptr &o) = delete;
    unique_ptr<T> operator=(const unique_ptr& o) delete;
    unique_ptr(unique_ptr&& o): ptr{o.ptr}{
        o.ptr = nullptr
    }
    unique_ptr<T>& operator=(unique_ptr&& o) {
        delete ptr;
        ptr = o.ptr;
        o.ptr = nullptr
        return *this;
    }
    T& operator*(){return *ptr}
};
/*
unique_ptr in your code indicates ownership over resource
automatically deletes heap resources when it goes out of scope
raw ptrs do not indicate ownership
should enevr delete a unique ptr
get raw ptr with .get()
*/

// you can have multiple pointers but no 2 unique pointers can point to the same thing!
// unique pointersare used for ownership, for example a grid owns a cell (unique pointer used!)

void foo(unique_ptr<T> pfoo) {
    //..
}

unique_ptr<myclass> p{new Myclass{}};
foo(p); // error copying unique pointer into foo's parameter

// proper way - move the unique pointer arg into the parameter
foo(std::move(p)); // works! but foo takes ownership so when foo goes out of scope we lost the pointer


void bar(myclass *p) {
    //...
}

unique_ptr<myclass> p{new myClass()};

bar(p.get()) // passing raw pointer in, does not transfer the ownership to bar
// so when old function pops off the stack p get dealloc


// as return types
unique_ptr<T> foo() {
    auto p = make_unique<T>();
    return std::move(p);
    //return p; also works bc of elision

    // return by value is treated as a move
}