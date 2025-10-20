#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

// example: printing all lines in the file

void writeFile(string file = "file.txt") { // defeault parameter optional
    string line;
    ifstream ifs{file};

    while (getline(ifs, line)) { // first arg is A STREAM ALWAYS
        cout << line << endl;
    }
}