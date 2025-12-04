struct Vec{
    int x,y;
    Vec (int x, int y): x {x}, y{y} {};
};

// Errors
Vec *vp = new Vec[10]; // Error! Init requires Vec() to exist
Vec vs[10];


/*
~~~ OPTIONS ~~~
- provide default ctor
- stack
- head
*/


int main(){
    // Stack
    Vec vs[2] = {Vec{0,0}, Vec{1,1} // ....
    };

    // Heap (array of pointers)
    Vec **vp = new Vec* [2];
    vp[0] = new Vec{0,0};
    vp[1] = new Vec{1,1};
}
