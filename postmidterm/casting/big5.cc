// dynamic references give us a soln to the polymorphic big 5 problem

text& operator=(const book& o) {
    const text& temp = dynamic_cast<const Text&> o;

    if (this == &tmp) return this; // self assn

    book::operator=(o);
    topic = tmp.topic;
    return this*;
}