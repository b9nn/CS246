// steps for object creation

//  - space is created
//  - fields are initialized
//  - ctor body runs

// when construcitng anything use the MIL, efficiency and compilation

// exmaple design a ctor for the basis class

class vec {
    public:
        int x, y;
        vec(int c1, int c2):
            x{c1}, y{c2}{} // no semi colon after the MIL body
};

class basis {
    public:
        vec u, v;
        basis(const vec& vec1, const vec& vec2):
            u{vec1}, v{vec2}{}
};

// the order of the fields within the MIL do not matter!

// an MIL can be used to initalize const and ref fields --> an advantage

// note that the compiler provides a default for all the big5

