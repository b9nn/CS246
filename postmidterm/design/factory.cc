/* problem we want to write a game with 2 kidn sof enemies (turtle and bullet)
    - we want one class (Level) to control creation of enemies classes and objects
    -  dont want client to be abel to create enemies

idea: put a factory method in level that creates enemy objects

        ------------
        |   Enemy  |
        ------------
        ^
        |
    ----------    
    | Turtle |
    ----------

*/

class level {
    //...
    public:
    virtual enemy* creatEnemies() = 0;
};

class easy : public level {
    //...
    public:
    Enemy* creatEnemies() override {// create some turtles (easy)
        }
};

class hard : public level {
    //...
    public:
    Enemy* creatEnemies() override { // create some bullets

    }
};

int main() {
    level* l = new easy;
    Enemy* e = l->createEnemies();

    // level controls enemy ctor
}