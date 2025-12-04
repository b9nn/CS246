struct constStudent
{
    int grade;
    int callcount;
    void bathroomBreak() const {++callcount} // error! not supposed to mutate
};

struct mutateStudent{
    mutatable int callCount = 0;
    void bathroomBreak() const {++callCount} // works! mutatbale overrides
};
