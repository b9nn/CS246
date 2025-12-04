struct Node {
    int data;
    Node *next;
};

class List {
    struct Node;
    Node *head;

    public:
    class iterator {
        friend class List;
        Node *curr; // current node the iterator is representing
        public:
        explicit iterator(Node *p): curr{p}{};
        int& operator*() {return curr->data;} // Access item
        iterator& operator++(){
            curr = curr->next;
            return *this; // question for kris why do we returned dereferenced?
        }

        bool operator!=(const iterator& other) {
            return !(*this == other); // comparing 2 objects in memory, wont star affect?
        }

        iterator begin() const {
            return iterator(head);
        }

        iterator end() const {
            return iterator (nullptr)
        }
    };
};

// Iteration
int main() {
    List lst;
    lst.addToFront(1);
    lst.addToFront(2);
    lst.addToFront(3);
    for (List::iterator it = lst.begin(); it != lst.end(); ++it) {
        cout << *it << endl; // overloaded deref
    }
}