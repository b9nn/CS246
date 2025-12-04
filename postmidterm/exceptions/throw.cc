int a = 9, b = 10;

try {
    if (int n = a + b, n != 21) // n only exists here
    // if n does not equal 21, it gets thrown
}
catch(int m) {
    cout << m;
}

// throwing a ref
class baseexn{}
class subexn : public baseenx {}

void foo () {
    subexn s;
    baseexn &b = s;
    throw b;
}

try {foo();}

// which one runs
catch (subexn &s){}
catch (subexn &e){}

// the type of the thrown reference determines the handler

// ans: baseexn handler runs