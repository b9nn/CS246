struct Student{
    int mt_grade;
    void cheat(const Student& other){
        mt_grade = other.mt_grade; // mutates this
    }
};

int main(){
    Student sam{100};
    Student billy;
    billy.cheat(sam); // billy is a cheater
}

// how to avoid this?
struct SafeStudent
{
    int grade;
    void cheat(const SafeStudent& other) const{
        grade = other.grade // wont compile, because this is const!
    }
};


struct cStudent{
    int grade;
    int foo1(){
        return 5;
    }

    int foo2() const{
        return 2;
    }
};

int hi(){
    const cStudent s;
    s.foo1(); // error, non const fn taking in a const
    s.grade = 100; // error modifying a const
    s.foo2(); // works! foo2 is a fn that takes in a const, so it can take in a const
}
