class X {
    int *xarr;
    public:
    X(int n): xarr{new int[n]}{}
    ~X() {delete[] xarr;}
};

class Y : public X {
    int* yarr;
    public:
    Y(int m, int n): X{m}, yarr{new int[n]}{}
    ~Y() {delete[] yarr;}
};

int main() {
    X* myY = new Y{1, 2};

    delete myY; // only deletes xarr since the method is not virtual!
    // since the method is not virtual, the method runs on the type on the LHS of assn
    // but since we allocated our yarr, we leak that memory
}

/*
     --- OBJECT DTOR --- 
    - dtor body runs
    - fields are dtord in reverse declaration
    - super class dtor runs
    - space is deallocation
*/

// the solution? virtual dtor so subclasses can overried dtor to delete thier own memeory!
class Y : public X {
    int* yarr;
    public:
    Y(int m, int n): X{m}, yarr{new int[n]}{}
    virtual ~Y() {delete[] yarr;}
};
