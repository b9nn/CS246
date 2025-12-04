class Vec {
    int x,y; //private scope
    public:
    void getX();
    Vec (int x, int y);
};

// Linked List w Encapsulation

//list.cc
export class List {
    struct Node; // privately nested class
    Node *head; // only acsessible within list

    public:
    void addToFront(int i);
    int& getithNode(int i);
    ~List();
} // refer to list-impl.cc