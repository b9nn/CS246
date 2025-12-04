// for a virtual override the parameters is the super and sub class must have the same paramter in the big5


class book {
    //...
    virtual book& operator=(const book& other){};

};

class text {
    virtual text& operator=(const book& o){}; // MUST BE A BOOK SAME SIG REQUIRED
};
