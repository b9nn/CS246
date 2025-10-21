// encapsulation hides the fields and methods of an object to control client access

// in the linked list example, we dont want our clients to create nodes


class List {
    struct Node {
        int data;
        Node *next;
        Node(int data, Node* next):
            data{data}, next{next}{}
    };
    Node* head;

    public:
    class iterator {
        Node* p;
        explicit iterator(Node* p):
            p{p}{}
        public:
        int operator*(){ // no paramenter bc they implicitly acts on p!
            return p->data;
        }
        iterator operator++() {
            p = p->next;
            return *this;
        }
        bool operator!=(const iterator& other) {
            return (p == other.p); // one field class so we just have to compare the one pointer
        }
    }
}