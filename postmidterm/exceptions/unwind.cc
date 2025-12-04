#include <stdexcept>
using namespace std;
void foo() {
    throw out_of_range{"oof"};
}

void g() {foo();}

void h() {g();}

int main() {
    try {h();}
    catch (out_of_range) {// do whatever to recover
        }


        // this code will unwind all the way until the error was caused (thrown in foo)

        /*
        we caught the out_of_range in main
        stack unwound itself until the exception is caught OR program terminations (main is unwound)

        note: most exceptions are classes
        */
}