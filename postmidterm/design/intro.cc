class list {
    struct node {
        int data;
        node* next;
    };
    //...
};

// but what if we want to store other types? copy and paste our code?

/*
a template class is a class parameterized  type --> dynamically add types to classes
*/

// pass desired type in typename
template<typename T> class List {
    struct Node {
        T data; // type "T" data
        node* next;
    };
    public:
    class iterator {
        node *p;
        iterator(node* p): p{p}{}
        public:
        T& operator*(){} // abstract return type
        friend class list;
    };
    T ith(int i){};
    void addFront(const T& node){}
};

int main() {
    List<int> l1; // T = int
    List<List<int>> l2; // T = List<int>
    l1.addFront(42); // adds 42 to the front
    l2.addFront(l1); // adds the whole linked list since l2 is of type List<List<int>>
    List<int>::iterator begin = l1.begin();

    // compiler converts client types into code before compiling!
}
