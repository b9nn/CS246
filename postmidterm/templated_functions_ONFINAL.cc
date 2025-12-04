template<typename T>
T min(T x, T y) {
    return x < y ? x : y;
}

int main() {
    int x = 9, y = 10;
    min(x, y); // compiler infers T based on the types of x and y

    // what if function doesnt have paramters? --> explicitly tell compiled what type is
    min<int>(6, 7);
    min("six", "seven");
    min(true, false);

    // min compiles iff the provided type "T" has a operator < defined
    min(Book{}, Book{}); // would error out bc book does not have the operator

    min(6, 8.5); // ERROR two types the function min expects one overloaded type
    min<int>(6, 8.5); // works!
}


// abstract iterator
void foreach(AbstractIterator start, AbstractIterator end, int (*f)(int)) {
    while (start != end){
        f(*start);
        ++start;
    }
}

// what if we templated
template<typename iter, typename Fn>
void foreach2(iter& start, iter& end, Fn f) {
    while (start != end) {
        f(*start); // calls iterator dereferenced method
        ++start;
    }
}

void foo(int n) {cout << n;}
int arr[] = {1, 2, 3, 4, 5, 6, 7};

foreach2(arr, arr + arr.length(), foo);


// FINAL HINT
/*
when i am talking about postmidterm
    - singular long answer premidterm (you've already done this uestion before BEEN TESTED HAD NIGHTMARES ABOUT)
    - DEFINETLY THE ITERATOR QUESTION FROM THE MIDTERM

- STARTED NOTES FROM KRIS HAVE THE FINAL QUESTIONS THAT ARE THEORETICAL
*/

template<typename t, typename ... Args>
void print(T x, Args ... rest) {
    cout << x << "->";
    print
}
