struct Node{
    int data;
    Node *next;
};

Node getNode(){
    Node n;
    return n;
} // n is copied and returned to the user. this method is very expensive

// DANGLING POINTER
Node* getNode(){
    Node n;
    return &n;
} // wont work the adress of the node is popped since it exists in stack space,
//  and stack-allocated memory is deallocated when the function has run to completion