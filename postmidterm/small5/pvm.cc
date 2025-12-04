#include <string>

class abstractbook {
    string title;
    int len;
    protected:
    abstractbook& operator=(const abstractbook& other){};
    public:
    abstractbook(){};
    virtual ~abstractbook() = 0; // purely virtual
};

class normalbook : public abstractbook {
    int myfield;
    public:
    normalbook(){};
    ~normalbook(){};
    normalbook& operator=(const normalbook& other) { // only gets called when assigning from a normal book
        abstractbook::operator=(other); // call superclass big5
        myfield = other.myfield; 

        return *this;
    }
};

// when implementing purely virtual methods, the dtor must be a pvm, because subclass dtor class superclass dtor
