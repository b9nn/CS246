float Student :: grade(){ // :: is the scope resolution operation
    return ass * 0.4 + mt * 0.2 + final * 0.4
}

// method grade() in class student


// defining a constructor
Student :: Student (int assn, int mt, int final){
    this->assn = assn;
    this->mt = mt;
    this->final = final;
}

/*
 advantage of constructors: they are fns

    - you can write complex code in the inits
    - default paramters, overloading. 
    Example:
*/

struct Student{
    ...
    Student(int assn = 0, int mt = 0, int final - 0)
}

Student :: Student(int assn, int mt, int final){
    this->assn = assn;
    mt = mt
    final = final
}

//main.cc
Student sam{60,70,80};

// the following are identical calls
Student billy;
Student billy{};

