class Book {
    protected: // the protected keyword allows for derived class to acsess would-be private fields + methods
    // client still no access
    string title;
    int len;
    public:
    Book(string s, int l):
        string{s}, len{l}{}
};

class Text : public Book {
    string topic;

    //...
    public:
    void addPages(int n) {
        length += n;
    }
};

int main() {
    Text t{"cs", 10, "academics"};
    t.addPages(1); // works
    t.length; // cannot access the length (STILL PROTECTED)
}

// BETTER IDEA: private fields + protected acsessors and mutators
class Book {
    string title;
    int len;
    protected:
    void setLen(int n) {
        len = n;
    }
    void getLen(){
        return length;
    }
    public:
    //...
};


