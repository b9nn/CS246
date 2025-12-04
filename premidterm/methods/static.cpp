// static fields --> associated with a class itself and not with any particular object instance

// Example, count number of students that exist at a time

struct Student{
    inline static int numStudents = 0;
    Student(): ...{ // MIL
        ++numStudents; // increases the static shared by all objects
    }
};

// Another one (static methods)
struct Student
{
   inline static int numObjects;
   Student (): {numObjects++;}
   static void howMany() {cout << numObjects}
};

Student sam{1,1,1}; // numObjects = 1
Student ben{1,1,1}; // numObjects = 2
cout << Student::howMany(); // prints 2
cout << Student::numStuds; // prints 2

