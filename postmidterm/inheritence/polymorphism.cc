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
};

int main() {
    book* myBooks[10]; // array of book pointers
    // a max of books texts and comics (polymorphism = many types into 1 type)
    for (int i = 0; i < 10; ++i) {
        cout << myBooks[i]->isHeavy();
        // since the array is pointers and method is virtual calls various isHeavy() methods
    }
    // polymorphisms allow us to represent many types under one abstraction
}

// POLYMORPHIC ARRAYS
class vec2d{int x, y;};
class vec3d : public vec2d {
    int z;
    void f(vec2d arr[]) {
        arr[0] = vec2d{1,2};
        arr[1] = vec2d{3,4};
    }
};

int main() {
    vec3d myarr[2] = {{1,2,3}, {4,5,6}};
    f(myarr); // legal but data misallignment occurs
    // lesson: never use arrays of objects polymorphically
    // but always use arrays of object pointers polymorphically
}
