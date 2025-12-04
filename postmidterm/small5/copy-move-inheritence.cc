

#include <string>

export module reading;
export class book {
    string title;
    int len;
    public:
    //.. all of the big 5 defined here
};

export class text : public book {
    string topic;
    public:
    // no copy or move ctor or assigners
};

int main() {
    text t{"algorithms", 300, "cs"};
    text t2 = t; // should be copy ctor but we have none defined for text!

    /*
    ends up calling book's copy constructor, then does a field by field init of text's fields
    */
}

