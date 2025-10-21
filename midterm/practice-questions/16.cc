#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

// what is wrong with this implementation of a grade method?
int Student::grade(const Student& s) const {
    int grade = (assns + mt + final) / 3;
    return grade;
}
