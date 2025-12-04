module vec; // imports the vec interface from vec module

 Vec operator+(const Vec& v1, const Vec& v2){
    Vec v{v1.x + v2.x, v1.y + v2.y};
    return v;
 }