/*
vectors follow RAII --> when a vector does out of scope it deletes it's internal array (delete [])
note that the contents are not deleted

SUMMARY:
    vector<int> --> vector owns it's objects
    vector<int*> --> vector does not own it's contents
    vector<unique_ptr<int>> --> vector owns it's contents
*/

#include <vector>
void foo() {
    std::vector<int> v;
} // when foo ends the VECTOR ARRAY IS FREED (NOT CONTENTS)

// problem:
void bar() {
    std::vector<int*> vptr;
} // none of the dynamically allocated elements are deleted (memory leak)

// work around? enfore ownership of the contents to the vector so we can use RAII (vector going out
// of scope deletes the contents it wants)

void explicitvector() {
    std::vector<int*> v;
    //...
    for (auto &p : v) { // works! but we had to define an explicit for loop :(
        delete p;
    }
}

void implicitvector() { // vector OWNS it's cntents
    std::vector<std::unique_ptr<int>> v;
} // array is freed same with internal pointers

