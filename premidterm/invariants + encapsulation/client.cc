int main() {
    List lst;
    lst.addToFront(4);
    lst.addToFront(2);
    lst.addToFront(3);
    for (int i = 0; i < size; ++i) { // O(n^2)
        int data = lst.getithNode(i);
    }
}

/*
Only List can crete and manipulate Nodes
--> guarantee invariant that *next is nullptr or new Node

Client cant traverse linked-list node-to-node
--> calling getithNode iteratively is O(n^2)

Solution: iterator pattern!

a class that iterators and or manages nodes
--> designed to iterator over nodes without exposing them
*/