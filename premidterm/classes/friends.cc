class vec {
    int x,y
    //...
    public:
    int getX() {return x;} // now we can not add friend since these methods are already public
    int getY() {return y;}
    void setX(int x) {x = x};
    void setY(int y) {y = y};
    
    // friendship weakens encapsulation
    friend ostream& operator<<(ostream& out, const Vec& v); // delcaare that operator<< is a friendly function and can use vec's stuff
    
}


ostream& operator<<(ostream& out, const vec& v) {
    return out << v.get(X) <<", " v.get(Y) << endl
}
