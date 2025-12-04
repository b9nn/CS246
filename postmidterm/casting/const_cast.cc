// convert between const and non-const (can remove const)
void bar(int* p){};
void foo(const int *p){
    bar<const_cast<int*> p; // can send p to a non-const method
}
