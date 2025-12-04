/*
we can define the <=> operator to give us other relational operators (6 total)

helps with laziness
*/

class vec {
    int x, y;
    public:
    auto operator<=>(const vec& o); // will do a legographical field by field comparison
};


// THE FOLLOWING COMPARISON IS O(N)
class Node {
    int data;
    Node *next;
    public:
    auto operator<=>(const Node& o) {
        auto res = data <=> o.data;
        if (data != o.data) { // different data so return comparison operator and thats your answer
            return res; 
        }
        else if (!next && !o.next) {
            return std::strong_odering::equal; // both last node
        }
        else if (!o.next) {
            return std::strong_ordering::greater; // this > other (just like how abc < abcd)
        }
        else if (!next) {
            return std::strong_ordering::less; // this < other
        }

        else {
            return (*next) <=> (*o.next); // recursive call
        }
    }
};

// we can extend this comparison to our list class
class List {
    struct Node{...} // same node class as before
    int len;
    Node* head;
    public:
        bool operator==(const List& o) const {
            if (len != o.len) {
                return false;
            }
            else{
                return head <=> o.head
            }
        }
}
