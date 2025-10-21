// in this file I will explain the copy-swap idiom
#include <utility>

struct Node {
    int data;
    Node *next;

    //...
    void swap(Node& tmp){
        std::swap(data, tmp.data);
        std::swap(next, tmp.next);
    }

    Node& operator=(const Node& other){
        Node temp{other}; // call copy ctor on other into temp
        swap(temp); // swap old contents into temp
        return *this; // return deref with new content

    }
};