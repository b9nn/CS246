module reading

text::text(const Text& other):
    book{other.book}, topic{other.topic}{}

text& text::operator=(const text& other) {
    book::operator=(other);
    topic = other.topic;
    return *this;
}

text::text (text&& other):
    book{std::move(other)} // pass as an rval so we know to call books move ctor
    topic{other.topic}{}

text& text::operator=(text&& other) {
    book::operator=(std::move(other)); // pass an rval so we know to call book's move ctor
    topic = std::move(other.topic);
    return *this;
}

// std::move(x) --> treat x like an rvalue

int main() {
    text t1{"life", 2 "idk"};
    text t2{"taxes", 50, "myth"};

    book* bp1 = &t1;
    book* bp2 = &t2;

    bp1 = bp2; // runs books copy ctor! since none of the methods are virtual compiler defaults
    // to the type on the lhs of assignment
}

