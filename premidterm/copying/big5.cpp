struct Node{
    int data;
    Node *next;

    // ...... //
};

Node n1 = Node{1, new Node{2, new Node{3}}};
//   move ctor            node ctor twice

Node n2 = n1; // Copy ctor
// not copy-assn because we are init a new node

n1= n2;
// copy-assn ctor, copying and assigning to n1

n1 = Node{2};
// move-assn operator (no init)