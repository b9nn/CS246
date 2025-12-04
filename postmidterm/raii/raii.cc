// resource allocation is initialization
//idea : wrap heap allocated resoruces in stack allocated data

struct stack {
    myclass* p;
    stack(myclass* ben) : p{ben}{}
    ~stack() {delete p;}
};

void foo {
    myclass mc;
    stack p{new myclass}; // protected heap memeory
    bar();
}
// when void foo goes out of scope it will delete mc and p even if bar throws

