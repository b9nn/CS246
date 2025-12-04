// consdier the following class definitions 

class Book {
    string title;
    int length;
};
class Text {
    string title; // same as book
    int length;     // ""
    string topic;   // different from book
};

class Comic {
    string title; // same as book
    int length; // ""
    string hero;    // different from book
};


// classes or so similar, maybe we can conjoin them?
// we could make an array that is a mixture of these objects,
//      -> text and comic book just have one extra field so we can use inheritence


// derived class inherits the public and protected components of te base class, but still has no private acsess

// book is base (superclass) , text is derived class
class Text : public Book {
    string topic;
    public:
        Text(string title, int len, string topic):
            Book{title, length}, topic{topic}{}

};

text t{"mylife", 10, "comedy"} // works!

