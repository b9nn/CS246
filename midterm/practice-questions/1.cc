#include <iostream>
using namespace std;

// what does this print with the input:
// 5
// ben
// 1

int main() {
    int i = 59;
    while(true) {
        cin >> i;
        if (cin.fail()) {
            cin.clear(); 
        }
        cout << i << endl;
    }
}