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

    // steal others memory, but we dont want to the automatic dtor to delete that memory
    // WHEN EVER AN R VALUE IS PRESENT, THATS THE QUEUE FOR THE MOVE CTOR
    // rvalues come when we are assinging something to a temp
    Node(Node&& other):
        data{other.data},
        next{other.next}{
            other.next = nullptr;
        }
};


Node plusOne(Node n){
    for (Node *pn= &n; pn != nullptr; pn = pn->next){
        ++(pn->data);
    }
    return n;
}

Node n1{1, new Node{2, nullptr}};

Node n2 = plusOne(n1); // move ctor

