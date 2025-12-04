struct Node{
    int data;
    Node *next;
};

int main(){
    Node n1{1, new Node {2, nullptr}};
    Node n2{6, &n1};
} // when main ends, dtor on n1 and n2 run

/*
what happens wen stack pops?

n1 is deleted first, then n2 trys to delete n1
|
---> dtor assumed thta next is a nullptr or newNode (not freed memory)

invariant: a statement or condition set on the code that must be true, think pre and postconditions
you CANNOT assume that a client will adhere to all your invariants. guard rails must be enforced

encapsulation: a way to enforce invariants. restricting client acsess to disobey invariants
*/

struct Vec {
    Vec(int x, int y); // anything above private and public is assumed to be public
    //...

    private: // the following defn, fields, or declarations are not accessible outside our class
    // client cannot access
    int x,y;
    //...

    public: // anything under the public label can be accessed outside the class (clients can play w)

    void getX();
};

Vec v = Vec(1,2); // public ctor so it works
v.x; // private field --> Error! Client can't access
v.getX(); // public method -> works


// struct --> assumes public visibility until specified otherwise
// class --> assumes private visibility until specified otherwise