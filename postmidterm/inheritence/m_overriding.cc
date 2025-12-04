class book {
    protected:
    int len;
    public:
    bool isHeavy(){
        return len > 200;
    }
};

class comic : public book {
    string hero;
    public:
    bool isHeavy() {
        return len > 30;
    }
};

int main() {
    book b{"small", 50};
    comic c{"big", 50, "spiderman"};
    // even tho they ar enot properly overloaded as per our old conventions, this works

    cout << b.isHeavy() // False
    << c.isHeavy(); // True
}

// since comic is a book the following IS VALID
book b = comic{"big", 10, "spiderman"};
b.isHeavy(); // what runs? comic or book's method
//      Answer: book :: isHeavy()
// see iPad notes for explanaiton