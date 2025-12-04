struct Vec{
    int x, y;
};

Vec v1{1, 2};
Vec v2{6, 7};

 // HOW TO ADD THEM?

 // OPTION A: 
 Vec v3{v1.x + v2.x, v1.y + v2.y}; // too manual, define a fn

 // OPTION B:
 Vec operator+(const Vec& v1, const Vec& v2){
    Vec v{v1.x + v2.x, v1.y + v2.y};
    return v;
 }

 Vec v3 = v1 + v2 // OVERLOADS (CALLS FUNCTION)


 // SCALAR MULTIPLICATION

 Vec operator*(const Vec& v, const int k){
    return {k * v.x, k * v.y};
 }

 Vec v3 = v1 * 10;

 
 Vec v3 = 10 * v1; // ERROR, no  operator*(int, vec) DNE

 // SOLUTION, CREATE OEVRLOADED OPERATOR FN
 Vec operator*( const int k, const Vec& v){
    return v*k; // call overloaded fn
 }


 // the following also works:
 cout << v1 + v2 + v3 << endl;