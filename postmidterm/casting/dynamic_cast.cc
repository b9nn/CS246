// how can u know if a cast is valid?

book* b = // book or text pointer?

static_cast<text*>(b); // error of b is a book?

// soln? dynamic cast!

dynamic_cast<T>(var);
// preofrms the cast if valid, returns nullptr if invalid
// onyl works if a class has atleast one virtual method

text t* = dynamic_cast<text*>(b);
if (t != nullptr) {
    cout << "b is a text";
}
else {
    cout << "b is a book";
}

// works
text t1 {}
book& b1 = t1
text& t2 = dynamic_cast<text>(b1);

// doesnt work
book b2{}
book& b3 = b2
text& t3 = dynamic_cast<text&>(b3)


