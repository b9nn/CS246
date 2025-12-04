// if a class is not meant to have subclasses, use the final keyword when declaring/defining

class X {};
class Y final : public X{};

class Z : public Y{} // ERROR
