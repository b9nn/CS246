/*
coupling realtionship - how much models depend on eachother

high coupling = strong realtionship + high dependency

    === MODULES ===

lowest --> modules communication via functions with primitive type
    - modules pass arrays/objects around
    - modules affect eachothers control flow
    - modules share global data
highest --> modules have complete acsess to eachother (friends)

COUPLING = how much MODULES interactwith eachother

COHESION = how much THE A MODULE INTERACTS WITH ITSELF

lowest --> module of unrelated items <utility>
        - contents share a common theme without interacting <algorithm> (a sorting module)
        - contents manipulate a localized state 
        - elements share/pass data around to eachother
highest --> element cooperate to preform 1 task

the goal is LOW COUPLING AND HIGH COHESION
*/


// special case - circular dependency

export module myA;
import myB;

export class A {
    B y;
};

export module myB;
import myA;

export class B {
    A y;
};

// solution A & B must be in same module

class B; //promise that the class B exists

class A {B* y;}; // Works! Compilier knows of B
class B {A* y;}; // fufilling promise