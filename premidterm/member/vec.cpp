struct vec{
    int x, y;
    vec operator+(const vec v){ // hidden field called "this"
        // called as v1 + v2 (v1 is the "this", v2 is the argument)
        return {x + v.x, y + v.y};
    }
    vec operator* (const int k){ 
        return {x*k, y*k};
    }

    // implicitly works with v * 5, but NOT 5 * v, must be defined outside
    // THIS must be on the left side of the operator
};

    
vec v1 = {1, 2};
vec v2 = {3, 4};

/*
what about io?
- must be defined outside vec class
*/

// all operator functions should be memeber fns

    