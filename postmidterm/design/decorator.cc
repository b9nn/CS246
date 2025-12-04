/* decorator pattern - satisfys enhacning objects at runtime
add new functionality/features at runtime

    - start with a basic object
    - wrapping new functionality at runtime

    ---------------------------------------------
    |       * PIZZA (abstract super class*      |
    |-------------------------------------------|
    |   +*price() : float* (virtual method)     |
    |   +*desc() : string* (virtual method)     |
    ---------------------------------------------
                  ^                     ^
                  |                     |
                  |                     |     
                  |               -----------------------------------------------  
            CRUST & SAUCE         |            *Decorator* (abstract)           | 
                                  |  #component : *Pizza (# = protected method) |
                                  -----------------------------------------------  
                                                             ^
                                  ---------------            |
                                 | Stuffed Crust | ----------|
                                  ---------------      

 */

#include <string>
class pizza { // abstract base class
    public:
    virtual float price() = 0;
    virtual string desc() = 0;
    virtual ~pizza();
};

class crustandsauce : public pizza {
    public:
    float price() override {return 6.00;}
    string desc() override {return "pizza";}
};

// we dont want a subclass for every combination! lets just decorate the base case (crust and sauce) at runtime so we can have extra toppings

class decorator : public pizza {
    protected:
    pizza* component;
    public:
    decorator(pizza *p): component{p}{}
    virtual ~decorator(){delete component;}
};

class stuffedcrust : public decorator {
    public:
    stuffedcrust(pizza *p): decorator{p}{}
    float price() override {
        return 2.00 + component->price();
    }
    string desc() override {
        return component->desc() +  "with stuffed crust";
    }
};

class topping : public decorator {
    string topping;
    public:
    topping(pizza *p, string top): decorator{p}, topping{top}{}
    float price() override {
        return 1.00 + component->price();
    }
    string desc() override {
        return component->desc() + ", " + topping;
    }
};




