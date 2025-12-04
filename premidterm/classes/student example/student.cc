// this is an interface file

struct Student{
    int assn, mt, final; // this is called a field
    float grade(); // this is called a method
};

// variables of a class are called fields
// funtions of a class are called methods

// classes are just structures that can contrain fns (blueprint)
// object: an instance of class (an implementation of a class)

// AN EQUIVALENT DEFINITION - using "this"

struct Student{
    int assn, mt, final; // this is called a field
    float grade(){
        return this->assn * 0.4 + this->mt * 0.2 + this->final * 0.4; 
    } // "this" is an autofilled reference to any object
};


// a constructor a method that initializes objects

struct Student{
    Student(int assn, int mt, int final)
};