// implementing the big 5 for the student class

struct Student {
    int assn, mt, final;
    Student(int x, int y, int z):
        assn{x}, mt{y}, final{z}{
            assn = assn ? assn < 100 : 100;
            mt = mt ? mt < 100: 100;
            if (final > 100){
                final = 100;
            }
        }
    Student(const Student& other):
        assn{other.assn}, mt{other.mt}, final{other.final}{}
    
    Student(Student&& other):
        assn{other.assn}, mt{other.mt}, final{other.final}{
            other.assn = 0;
            other.mt = 0;
            other.final = 0;
        }

    Student operator=(Student& other) {
        if (this != &other) {
            assn = other.assn;
            mt = other.mt;
            final = other.final;
        }
        return *this;
    }

    Student operator=(Student&& other) {
        assn = other.assn;
        mt = other.mt;
        final = other.final;

        other.assn = 0;
        other.mt = 0;
        other.final = 0;
    }
};


// and again for the node class

struct Node {
    int data;
    Node *next;

    Node(int n, Node* next):
        data{n}, next{next}{}

    ~Node() {
        //delete[] next; 
        // the above is not correct, firstly you onyl use [] whem recursively deleting an array, and the command below
        // already recurses trhough next and deleets until nullptr
        // deleting nullptr is vlaid in cpp
        delete next;
    }
    
    Node(Node& other):
        data{other.data}, next{other.next ? new Node{*other.next} : nullptr}{}

    Node(Node&& other){
        //delete[] next; // in the move ctor we are init a new node,so we dont need to delete next
        data = other.data;
        // next = other.next ? new Node{*other.next} : nullptr; // we are moving not doing a deep copy
        next = other.next;

        other.data = 0;
        other.next = nullptr; // takes other away from the linkedlist entirely, no association with any linked list

        /*
        while (&other != nullptr) {
            Node *temp = &other;
            other = nullptr;
            other = temp->next;
        }
        */
    }

    Node& operator=(const Node& other) { // should return Node reference and must take in a const
        if (this != &other) {
            data = other.data;
            delete next;
            next = other.next ? new Node{*other.next} : nullptr;
        }
        return *this;
    }

    Node& operator=(Node&& other) {
        delete next;
        data = other.data;
        next = other.next;

        other.data = 0;
        other.next = nullptr;

        return *this;
    }
};
