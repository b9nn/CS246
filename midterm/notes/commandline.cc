#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// argc --> arguments passed in command line, INCLUDING EXECUTABLE NAME
// argv --> array of arguments, with the first one being the name of the executable (has last entry as argv[argc - 1])

// note: argv is stored as C strings, must convert to C++ strings before using C++ operations

int main(int argc, char **argv) { // array of arrays (pointer to char pointers)
    for(int i = 0; i < argc; ++i) {
        string arg = argv[i];
        // do what ever is needed, but conversion is neccessary
    }
}

/*
argv[0] = ['.', '/', 'p', 'r', 'o', g', '\0'] --> C style string so has null terminator
argv[1] = ['1', '\0'] --> still a C style string
argv[argc] = NULL (indxed as a string would be)
*/

// sum all args
int sumArgs(int argc, char **argv) {
    int total = 0;
    for(int i = 0; i < argc; ++i) {
        string curr;
        int n;
        if (istringstream iss{curr}) {
            iss >> n;
            total += n;
        }
        else{
            break;
        }
    }
    cout << total << endl;
}



