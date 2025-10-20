#include <iostream>
#include <string>
using namespace std;
int main() {
    int i = 1;
    string s;
    while (cin >> s){
        cout << "Word [" << i << "]: "<< s << endl; // what does this look like for "a     bc  d a e"??
    }
}
