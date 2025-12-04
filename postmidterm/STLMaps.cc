/*
STL Maps

Container (like vector<T>) that associate a unique set of keys to values

example: array of string numbers to int
*/

#include <map>
#include <string>
#include <iostream>

using namespace std;

int main() {
    // map<key_type, val_type>, <keys, vals>
    map<string, int> m;
    m["one"] = 10;
    m["two"] = 2;
    m["one"] = 1; // fixes our error on line 17
    cout << m["one"]
    << m["DNE"]; // prints 0
    // if a key is not found, it is automatically inserted with it's value being
    // that of default construction
    // in this case assigns 0
    // m = {"one": 1, "two": 2, "DNE" : 0}
    m.erase("DNE"); // m = {"one" : 1, "two" : 2}

    bool found = m.count("DNE"); // 1 if found, 0 if not

    if (m.find("one") != m.end()) {
        // "one is in m"
    }
    else {
        // "one" is not in m
    }

    //iteration occurs in sorted key order
    for (auto&p : m) { // p == std:pair<stirng, int>
        cout << p.first << p.second;
        //      key         value

    }
    

}