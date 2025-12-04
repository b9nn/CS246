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

// slicing doesnt occur with pointers and references SINCE THEY HAVE FIXED SIZE NO MATTER WHATG POINTED AT
int main() {
    comic c{"marvel", 50, "flash"}; 
    book *bp = &c;
    comic *cp = &c;
    book& rb = c;

    cout << bp->isHeavy() // false
    << cp->isHeavy() // true
    << rb->isHeavy(); // false
    
    // COMPILER USES THE METHOD THAT IS OF THE TYPE OF THE PTR OR REFERENCE

    // how do i ensure a comic acts like a comic regardless of what points to it or references it --> virtual methods
}

class book {
    protected:
    int len;
    public:
    virtual bool isHeavy(){ // lets subclass override isHeavy at runtime!
        return len > 200;
    }
};

class comic : public book {
    //...
    public:
    bool isHeavy() override {return length > 30};   
}

int main() {
    comic c{"marvel", 50, "flash"}; 
    book *bp = &c;
    comic *cp = &c;
    book& rb = c;
    book b = c;

    // virtual method USESES the OBJECT TYPE OF METHOD (book pointer -> book pointer -> comic ~ still uses comic.isHeavy()) 
    cout << bp->isHeavy() // true
    << cp->isHeavy() // true
    << rb->isHeavy() // true
    << b.isHeavy(); // false (not a pointer, so still slices)

    // virtual methods choose which method to run based on the actual type of the object (absolute RHS) at runtime
}

// the difference between virtual and non-virtual method is the determination the compiler makes when executing overloading and inherited methods
