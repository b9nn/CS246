class Student {
    protected: // bc it has one pvm the whole class becomes abstracted
    int numCourses;
    public:
    virtual int fees() const = 0; // doesnt set it to 0, just says it's purely virtual!
};

struct Regular : public Student {
    int fees() const override {return 1200 * numCourses;}
};

struct CoOp : public Student {
    int fees() const override { return 1500 * numCourses;}
};

int main() {
    Student s; // error! cannot initiazlize a purely virtual class!
}
