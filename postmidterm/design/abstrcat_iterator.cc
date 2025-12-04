template<typename T> class abstractiterator {
    public:
    virtual T& operator*() const = 0;
    virtual bool operator=(const abstractiterator& o) const = 0;
    virtual abstractiterator& operator++() = 0;
    virtual ~abstractiterator();
};

class list {
    struct node{
        int data;
        node *next;
    };
    public:
    class iterator : public abstractiterator<node> {
        // implement all pvms from abstract iteraotr class
    }   
};