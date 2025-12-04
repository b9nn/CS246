/*
l-values are anything with persistent memory address (&)
Consider:
*/

struct Node{
    int data;
    Node *next;
    Node& operator=(const Node& other){
        if (this == &other){
            return *this;
        }
        Node *temp = next;
        data = other.data;
        next = other.next ? new Node{*other.next} : nullptr;
        delete temp;
        return *this;
    }
};

Node plusOne(Node n){
    for (Node *pn= &n; pn != nullptr; pn = pn->next){
        ++(pn->data);
    }
    return n;
}

Node n1{1, new Node{2, nullptr}};

Node n2 = plusOne(n1); // what ctor is this?

/*
plusOne(n1) returns a node

therefore n2 must be constructed with a copy constructor (since = is defined as such)
but copy const ref to a Node, plusOne does not return a ref? so what is other?
    - plusOne does not have any lvalue

- compiler creates a temp address for plusOne's returned object
- runs copy ctor on n2
- deletes temp object (dtor)

compiler creates a deep copy temp, then deletes it. use it!

this motivates our defn of rvalues, defined by thier &&, rvalues are temp objects
with temp addresses that are deleted once used!
see move-ctor

*/