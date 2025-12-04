//import <utility>;
#include <utility>

struct Node{
    int data;
    Node *next;

    // swapping
    void swapNode(Node& other){
        std :: swap(data, other.data);
        std :: swap(next, other.next);
    }

    // better swapping
    Node& operator= (const Node& other){
        Node temp = other; // copy ctor
        swapNode(temp);
        return this;
    }
};