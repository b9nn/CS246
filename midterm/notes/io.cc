/*
- main functions must return an int
- import statments speed up the compilation by caching --> inlcudes are slightly slower

*/

#include <iostream>
using namespace std;

int main() {
    //... insert function body
    return 0; // default return value, DOES NOT HAVE TO BE SPECIFIED
}

// >> == get from
// << == put to

cin >> x;
cin.fail(); // set to true when read fails (incorrect type) or out of range
// cin.fail() will have a true fail bit if you cin something of the wrong type
cin.eof() // set to true if an eof is encountered

// if the fial bit is activiated you must clear it before reading more ints, or else you cant cin anything else

int main() {
    int i;
    while(true) {
        cin >> i;
        if (cin.fail()) {
            cin.clear(); 
        }
        cout << i << endl;
    }
}

/*
Lets assume the following input:

3
ben
1

read 3 --> prints 3
read ben --> cin.fail() --> cin.clear()
read ben and 1 --> cin.fail --> cin.clear()

ben is still in the input buffer! it never gets cleared so infinte fails!
prints 0 forever refer to 1 in the test folder

to clear the input buffer, run cin.clear
*/

int main() {
    int i;
    cin >> i;
    if (cin) { // valid, returns bool from last cin
        cout << i << endl;
    }
}

// CIN IGNORES LEADING WHITESPACE
