// REFERENCES
int y = 6;
int x = y;
int &z = y;
int *p = &z;

int main(){
    x = 10;
    z = 7;
    *p = 11;
}


/*
y = OxA..., y = 6 -- > y = 7 --> y = 11
x = 0xB..., x = 6 --> x = 10

z = &y, z = 6
p = &y and &z (the same)

*/


// int& *x; // invalid cannot point to a reference as its not its onw object in memory
int &&x; // cannot reference a reference

/*
Pass-By-Reference: fn makes a copy of the arguments passed to it
    - if args are huge copy can be expensive

Pass-By-Const-Reference
*/

int f (int& g){
    return g;
}

int h (const int& n){
    return n;
}

/*
f(5) = error! 5 does not have an adress in memory so you do not have a ref to it
h(5) = 5 works because n cannont CHANGE
 - compiler temporarily stores 5 in memory (giving it an adress for h to use!)
*/


