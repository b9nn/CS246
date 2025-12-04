#include <memory>
/*
basic guarantees
- if an exn occurs your program will be in a valid but unspecified state
    - no leaks, or mem corruption and invariants are maintained

strong guarantees
    - if foo throws an exn your program will be in a state as if foo never ran!

no-throw guarantee
    - foo never throws and always accomplishes its goal

*/

class a {
    public:
    void g(){}
};

class b {
    public:
    void h(){}
};

class c {
    a mya;
    b myb;
    public:
        void foo() {
            mya.g(); // may throw with string guarantee
            myb.h(); // may throw with string guarantee
        }
};

// FINAL QUESTION is c.foo() exception safe?

/*
2 cases a.g() or a.h() throws

if a.g() throws, since its strong guarantee so nothing happens?

if b.h() throws, a.g() still runs, so the a myA is modified THIS PERSISTS
we must undo the effects of a.g() to give foo a string guarantee (doesnt modify anything)

if foo doesnt undo what it does to A its not strong guaranteed!

thus foo is not exception safe!

solution: test if a and b both run first!
*/

class d {
    public:
        void foo() {
            a atemp, mya;
            b btemp, myb;

            // since a.g() and b.g() are strong if they throw the temps remain unchanged
            atemp.g();
            btemp.h();

            // what if our copy assn method throws! (bad alloc)
            // SO WE NEED ANOTHER NO THROW SWAP
            mya = atemp;
            myb = btemp;

        }
};

// soln: pointer-to-implementation idiom (PIMPL)

/*
RECALL: copying objects can throw std::bad-alloc
but copying pointer cannot! (since we dont allocate memory)
*/

class pimpl {
    public:
    a mya;
    b myb;
};
class e {
    std::unique_ptr<pimpl> p; // pointer to e's fields
    public:
        void foo() {
            auto temp = std::make_unique<pimpl>(*p);
            temp->mya.g();
            temp->myb.h();

            std::swap(p, temp);
        }
};

