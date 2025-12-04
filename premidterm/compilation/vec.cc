export module vec; // specific to interface files

export struct Vec{
    int x, y;
};

export Vec operator*(const Vec& v, const int k); // no body, just declaration