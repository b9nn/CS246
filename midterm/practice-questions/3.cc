#include <iostream>
using namespace std;

// what will this print with the same input as q1?

int main() {
    int i;
    while(true) {
        cin >> i;
        if (cin.fail()){
            if (cin.eof()) {
                break;
            }
            cin.clear();
            cin.ignore();
        }
        else{
            cout << i << endl;
        }
    }
}