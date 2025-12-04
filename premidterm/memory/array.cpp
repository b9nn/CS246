struct Node{
    int data;
    Node *next;
};


Node *single = new Node;
delete single;

Node *myNodes = new Node[10]
delete [] myNodes;

/*
HEAP ALLOCATED ARRAY
allocated memory in the form new[...], call delete [] --> recursively frees memory
*/
