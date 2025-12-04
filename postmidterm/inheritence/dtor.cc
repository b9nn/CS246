/*
when a subclass dtor runs it also calls the superclasses dtor
*/

// X is the super class, Y is a subclass

X* myY = new Y{10, 20};

delete X;
