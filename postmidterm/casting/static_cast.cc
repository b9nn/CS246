// static cast cast is used when types are semanticaly the same
// the PROGRAMMER is responsible for ensureing that the cast is valid

// example of safe cast: double to anint

double d;
void f(int d){}
void f(double d){}
f(static_cast<int>(d)); // casts the double to an int and calls f(int)

book* b = new text{};
text* t = static_cast<text*> b; // must ensure that b is a text for this to work