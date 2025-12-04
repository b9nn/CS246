// a constructor (ctor) is always called when an object is initialized
// if no ctor is defined, the compiler will run the default c-style constructor on that object
//  - ctor constructs any fields that are objects

struct Vec{int x, int y}

Vec v; // default ctor sets Vec(0, 0)

struct Vec{
    int x, y;
    Vec(int x, int y){
        this->x = x;
        this->y=y;
    }
};

Vec v1 = {1,2}; // works just fine
Vec v2; // does not work, no deault constructor is defined ERROR

// continuation

struct Basis{
    Vec v1, v2;
};

Basis b; // ERROR the vector method trys to apply a default ctor, but a constructor is defined for Vec

// proper def of basis

struct Basis{
    Vec v1, v2;
    Basis(){
        Vec v1{0, 1};
        Vec v2{2, 3};
    }
};

Basis b; // still does not work! 
// feilds are hit before the ctor body, so Vec v1, v2; erros bbc no default ctor

//SOLUTION: member initialzation list

Basis :: Basis(): v1{0, 1}, v2{2, 3}{ ...ctor body...}

struct Student{
    int assn, mt, final;
    const int uid;
    Student(int uid, int assn, int mt, int final):
        uid{uid}, assn{a}, mt{m}, final{f} {}
}
