/*
the template method pattern is used when a subclass needs to override parts of a superclass,
while allowing hte superclass to retain control over the order and structure of its methods
    - select methods are overrode, some are not
*/

// drawing red and green turtles
class turtle {
    public:
    void draw() {
        drawHead();
        drawShell();
    }
    private:
    void drawHead(){} // turtle controlled
    virtual void drawShell() = 0;
};

class greenturtle : public turtle {
    void drawShell() override {
        // fn body here
    }
};

class redturtle : public turtle {
    void drawShell() override {
        // fn body here
    }
};
