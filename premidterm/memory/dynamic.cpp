
struct Node{
    int data;
    Node *next;
};

Node *p = new(Node); // allocate memory

delete p; // free memory

/*
pointers exist on the stack, but the memory it points to exisits on the heap

all local variables exist in stack space

stack variables are deallocated AUTOMATICALLY when the stack gets popped (out of scope)
*/

void foo(int yfoo = 6){
    int xfoo = 7
}
int y = 10;
foo (y);

/*
---------------
---- STACK ----
---------------
-    int y    - * MAIN STACK
---------------
-   int y foo - * FOO STACK
-   int x foo -
---------------

*/


void foo(){
    int *xp = new int;
    *xp = 5;
} // WE NEVER FREE XP

int y;
foo();

/*
unlike the stack, heap memory remains allocated until the caller
deallocates it

---------------
-    STACK    -
---------------
-    int y    - * MAIN STACK
---------------
-   int* xp  - * FOO STACK
-             -
---------------
-      5      - * LEAKED MEMORY
---------------
-     HEAP    -
---------------

*/
