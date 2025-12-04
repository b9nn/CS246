/*
A UML Diagram shows ownership

for a class we must include:
    - class name
    - fields
    -methods

+ for public fields/methods
- for private fields/methods

-> composition (ownership)

*/

class Vec {
    int x, y;
    public:
        Vec (int x, int y);
};
class Basis {
    Vec v1, v2;
    public:
        Basis(): v1{1,2}, v2{3,4}{}
};

// a basis object owns a vector class (2 of them)

/*
if class A owns class B
    - B is not independent, it's identity is tied to class A
    - When A is destroyed, so is everything it owns, so B is also destroyed
    - When A is coped, so is everything it owns, so B is also copied

to show the vec-basis relationship via UML diagram
    - draw a COLOURED diamond around the basis class and draw an arrow connecting that to the vec class and state the # of instances
    - in UML we dont need to show any of the big5

// we use a coloured diamond because of ownership, direct owenrship exists bc basis calls vec ctor
*/


// a different example
class Goose {
    string thoughts;
};
class Pond {
    Goose* geese[10]; // 10 goose pointers
    public:
        //...
    ~Pond(){} // the pond doesn't delete it's geese
};

/*
Pond does not directly own geese because we dont allocate any memory, so they are just linked by a pointer array (DOESNT OWN RATHER "HAS")

Pond has a Goose
    - Geese exist independently of the pond
    - When pond is destroyed it doesnt take the geese with it, just the array of geese

To model the relationship via UML, we instead use a non-coloured diamond to signify "has" rather than "owns"

we can expressed the instances of geese in this case as 0...10

in general if we dont know how mant classes another will have we can use 0...* notation
*/
