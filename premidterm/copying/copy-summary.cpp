struct Student{
    int assn, mt, final;
    Student (int a = 0, int mt = 0, int final = 0): // ctor
        assn{a}, mt{mt}, final{final}{}
    Student(const Student& other): // copy constructor
        assn{other.assn}, mt{other.mt}, final{other.final}{}
    Student& operator={const Student& other}{ // copy-assn constructor
        assn = other.assn
        mt = other.mt
        final = other.final
        return *this;
    }
};

// limited by shallow copy