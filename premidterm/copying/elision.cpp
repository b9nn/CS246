struct Node{
    int data;
    Node* next;

    Node makeNode(){return {5, nullptr};}
    Node n = makeNode(); // what happens? could be move or copy ctor

    void foo(Node n){
        return;
    }
    Node foo(makeNode()); // values from makeNode is written directly into n
    // skips the move and copy/ctor
};

