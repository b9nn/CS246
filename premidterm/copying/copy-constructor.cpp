// COPY CONSTRUCTOR

struct Student{
    const int id;
    int assn, mt, final;
    Student(int id, int a, int m, int f):
        id{id}, assn{a}, mt{m}, final{f}{   // THIS IS THE MIL  // LEFT SIDE = RIGHT SIDE // ALLOWS CONSTS TO BE INIT
        // NOW THAT FIELDS ARE INIT WE CAN RUN CHECKS
        if (assn > 100) assn = 100;
     
    }
};

Student Ben {21138810, 100, 100, 100};
Student Josh = Ben; // copy constructor

/*
        How is Josh initialized?
- copy constructor
Student (const Student& other): // takes in a student reference
    assn{other.assn}, midterm{other.mt}, f{other.final}{}

"this" is josh --- "other" is ben 

a copy constructor as an object is being initialized as a copy of another object
        **A SHALLOW COPY**
*/


// ANOTHER EXAMPLE

struct Node{
    int data;
    Node *next;
};

Node *n = new Node{1,new Node{2, new Node{3, nullptr}}};

Node m = *n; // m gets field by field copy



// n []]--> 1 --> 2 --> 3
//             ^
//             |
// m [1, -------    // THE ONE IS ON THE STACK, NOT THE HEAP

// this motivates our definition of a way to have a deep copy

struct Node{
    int data;
    Node *next;
    Node(const Node& other):
        data{other.data},
        next{(other.next != nullptr)? new Node{*other.next}:nullptr}
};

// TERNARY OPERATOR
// cond ? ..runs if cond is true... : ...runs if cond is false...


/*
~~~ A Copy Constructor is called when~~~
- an object is being inited as a copy
- an object that is passed-by-value
- an object is returned by value
*/


// MIDTERM MC
struct Node{
    int data;
    Node* next;
    Node (int data): data{data}, next{nullptr}{}
};

int foo(Node n){n.data = 5};

foo(4); // WORKS, 4 IMPLICITLY CONVERTED TO A NODE
// errors and warnings do not exist here

// SOLUTION

Struct Node{
    ...
    explicit Node(int data)...
}

Node n{4}; // WORKS
foo(4); // DOES NOT WORK
foo(Node{4}) // WORKS
Node n2 = 4; // ERROR