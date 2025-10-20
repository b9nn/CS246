#include <iostream>
using namespace std;

// whats the diff between this and 3.cc?
int main() {
    int i;
    while(cin >> i) {
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