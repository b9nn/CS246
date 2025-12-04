/*
obervers are in charge of responding/reacting to changes in a subject
    1. subjects state is updated
    2. notifyObserver [subject's method] ---> notify() [an observe method]
    3. each observer responds to the subjects state change

example:
subject publishes tweet --> observer's [fans] respond if thier name is in the tweet
*/

#include <vector>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class observer {
    public:
    virtual void notify() = 0;
    virtual ~observer();
};

class subject {
    std::vector<observer*> observers; // vector of oberver pointers
    public:
    void attach(observer* ob) {
        observers.emplace_back(ob);
    }

    void notifyObserver() {
        for (auto ob : observers) ob->notify();
    }

    void detach(observer* ob) {
        for (auto it = observers.begin(); it !=observers.end(); ++it) {
            if (*it == ob) {
                observers.erase(it);
                break;
            }
        }
    }
    virtual ~subject() = 0;
};

class tweeter : public subject {
    ifstream in;
    string post;

    public:
    tweeter(const string& file): in{file}, post{""}{}
    bool tweet() {
        return getline(in, post);
    }
    string getState() {return post;}
};

class follower : public observer {
    tweeter* subject;
    string name;
    public:
    follower(tweeter* sub, string name):
        subject{sub}, name{name}{
            subject->attach(this);
        }

    void notify() override {
        string msg = subject->getState();
        if (msg.find(name) != string::npos) {
            // name is in message
            cout << "they said" + name + "!!!" << endl;
        }
    }
    ~follower() {subject->detach(this);}
};


    /**
     * Attempts to update the price of a Stock for a given ticker symbol to
     * price. If the Stock does not exist, a new Stock with the given ticker
     * symbol is added to the Market. If the Stock exists, its price is
     * updated.
     * @param symbol The ticker symbol of the Stock
     * @param price The new price of the Stock
     */
    void updateStock(std::string symbol, int price);