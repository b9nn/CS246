#include <vector>
using namespace std;

int main() {
    vector<int> v{1,2,3};
    v.at(0); // this turns out to be one
    v.at(1000); // exception! out of range!

    /*
    when an error condition occurs an exception is thrown.
        - compiler terminates program
        - compiler unwinds your program
    */

    #include <stdexcept>

    try {
        cout << v.at(1000); // error prone code is always nested within the try block
    }
    catch(out_of_range r) { // to handle exception
        cout << r.what(); // string repn error type
    }

}