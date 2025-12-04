#include <string>


class Book {
    string title;
    int length
    public:
    Book(string t, int l): title{t}, len{l}{}
};

// Text is a derived class of book (has full acsess to all of Book' public fields and methods NOT PRIVATE)
class Text: public Book { // in this case book is the baseclass or superclass
    string topic;
    public:
    Text(string t, int l, string topic):
        title{t}, length{l}, topic{topic}{} // error acsessing the book's private fields!
}

// the solution is to call the book ctor, bc it can create the fields as all Book member methods have access to books private fields

// SOLUTION
//but first

/*
    - Space is allocated
    *- Superclass default ctor runs (if exists)
    - fields constructed
    - ctor body runs

* - if no such ctor exiss, the subclasses job to run valid superclass ctor
*/

// EXAMPLE
class Text : public Book {
    //...
    Text(string s, int l, string top):
        Book{s, l}, topic{topic}{} // call superclass default ctor
}

// HOW CAN GIVE DERIVED CLASSES ACSESS TO BOOKS FIELDS? ---> protected visibility
// see protected.cc