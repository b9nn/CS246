/*
the standard template library is a large library of templated types
dynamic length array? --> vector
*/

#include <vector>
#include <iostream>
using namespace std;
int main() {
    vector<int> v{4,5}; // v = [4,5]
    vector<int> v2(4,5); // v2 = [5, 5, 5, 5] THIS ROUND BRACES ARE DIFFERENT
    v.emplace_back(6); // v = [4, 5, 6]

    // looping
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i] << endl;
    }

    // supports iterator
    vector<int>::iterator it = v.begin();
    for(; it != v.end(); ++it) {
        cout << *it << endl;
    }

    // supports automatic memory management! no new or delete needed!

    vector<int> v{4,5,6,7,8,9,10};
    v.erase(v.begin()); // v = [5, 6, 7, 8, 9, 10]
    v.erase(v.begin() + 2); // v = [5, 6, 8, 9, 10]
    v.erase(v.end()); // v = [5, 6, 8, 9]
    auto it = v.erase(v.begin()); // it = v.begin --> v = [6, 8, 9]
    v.erase(it); // erasing at given iterator it --> v = [8, 9]

}
