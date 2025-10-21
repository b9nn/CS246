#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
using namespace std;

/*
❓Question

Implement a class  that stores three integer fields — assns, mt, and final — and includes:

A constructor that initializes these fields using parameters with the same names.

A member function grade() 

Make sure to define the constructor outside the struct using the scope resolution operator ::.
Then, in main(), create three different Student objects using:

Direct list initialization

Copy-style initialization

Dynamic allocation on the heap

*/

// student-interface.cc

export module Student;

export class Student {
    int asnns, mt, final;
    Student(int assns, int mt, int final);
    int grade(const Student &s);
}

// student-impl.cc

module Student;

Student::Student(int assns, int mt, int final):
    assns{asnns}, mt{mt}, final{final}{};

int Student::grade(const Student& s){
    int grade = (assns + mt + final) / 3; // this is wrong, i am taking a student reference but i am referencng this liek its this->
    // so either remove the parameter or add the s.assns etc...
    return grade;
}

// client.cc
import module Student;
int main() {
    Student ben = {85, 85, 85};
    Student josh = ben;
    Student *s = new(Student{1,2,3});
}