#include <iostream>
#include <string>
using namespace std;

// c++ strings we dont care about the null-terminator, but you can still accsess it using methods

int main() {
    string b = "ben";
    string m = "mom";

    bool compare = b == m;
    compare = b != m;

    bool sort = b < m; 
    cout << sort << endl; // will print true, m is technically "bigger" think ASCII, m comes later

    cout << b.length() << endl; // note, an O(1) operation

    string f = b + m; // f = "benmom"

    string s;
    cin >> s; // reads in full string
    cout << s << endl; // outputs whole string

    // when reading from stdin, we read until WHITESPACE for strings
    // otherwise if we want to read in with white space until NEWLINE we can use:
    getline(cin, s);

    // takes in an istream, and a destination, optional third argument is the delimiter (where to stop reading)
}

