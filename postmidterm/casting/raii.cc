/*
to cast smart pointers
*/

// cast shared pointers to shared pointers
static_pointer_cst<T>(var);
reinterpret_pointer_cast<T>(var);
const_pointer_cast<T>(var);
dynamic_pointer_cast<T>(var);

// dynamic casting lets us know the runtime type of objects
void whatIsIt(shared_ptr<book> b) {
    if (dynamic_pointer_cast<text>(b)) {cout << "b is text";}
    if (dynamic_pointer_cast<comic>(b)) {cout << "b is comic";}
    else {
        cout << "b is a book";
    }
}

// this code is higly coupled ot book