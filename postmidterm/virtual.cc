class vec1 { // size is 8 bytes -> 4 for one int and 4 for the other
    int x, y;
    int foo() {}
};

class vec2 { // size is 16 bytes?
    int x, y;
    virtual int foo() {}
};

// why?

// recall

book* bookPtr = new Book/Text/Comic

pb->isHeavy();

/* since is heavy is a virtual method, the compiler uses the type that pb points to,
 (calls tht at method) compiler only knows the correct type at RUNTIME not in advance

for any class with atleast one virtual method
    - compiler creates a fn table called vtable
    - object instances will store a pointer ot it's own classes vtable
*/

class c {
    int x, y;
    virtual void foo() {}
    virtual int bar() {}
    void h() {} // not in the vtable since its not a virtual method
    virtual ~c(){}
};

c myC;

/*
vtables store function pointers, so each virtual method stores and extra 8 bytes

     -------         _____C's Vtable____
    |  vptr |------>|       "C"         |
    |   x   |       |       foo         |
c = |   y   |       |       bar         |
    |       |       |       ~C          |
    |       |       |                   |
     --------       |                   |
                    |                   |
                    |                   |
                    |___________________|



calling virtual methods
    - follow the vptr ot the object's class's vtable
    - fetch th ptr to the actual method from the table
    - follow the fn ptr and call the fn





*/

