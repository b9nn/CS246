#include <iostream>

using namespace std;

int main() {
    int f = 5;
    int&& r = (f+1); // 6
    int&& g = f; // f

    cout << r << endl;

}


