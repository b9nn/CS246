#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

int main() {
    string s;
    ifstream f{"file.txt"}; // defining a file stream for us to read into, cin exists by default, but we define what we want ot read from
    // cin is strandard inout so we dont need to define it --> it's default
    while (f >> s) {
        cout << s << endl;
    }
} // file automatically closes when popped off the stack


// STRINGSTREAMS
string intToString(int n) {
    ostringstream oss;
    oss << n; // stores int in oss
    return oss.str();
}


// string streams implicity cast ints into strings when you send them through
void allIntToString() {
    string s; // reads until whitespace
    while (cin >> s) { // will not fail even if it reads 5, bc after all its just text
        int i; // reads chars one at a time
        istringstream iss{s}; // wraps in a string stream, so we can get
        if (iss >> i){ // implicitly converts i into a str
            cout << i << endl;
        }
    }
}
