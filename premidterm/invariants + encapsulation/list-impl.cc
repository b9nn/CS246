module List;

struct List::Node {
    int data;
    Node *next;
    Node(int data, Node *next): data{data}, next{next};
    ~Node(){delete.next}; // how is this recursive
};

void List::addToFront(int i) {
    head = new Node {i, head};
}

int& List::getithNode(int i){
    Node* curr= head;
    for (int j = 0; j < i; ++j, curr = curr->next);
    return curr->data;
}