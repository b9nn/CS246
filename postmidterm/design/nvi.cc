/*
Non-Virtual Interfaces

A public method is an INTERFACE (promises invariants)
    - public methods must be non-virtual (we dont want the client to be able to override them)

All virtual methods must be private or protected
    - dtor is an exception, needs virtual to be overrode if additionally memory is alloc
    - dot is public
*/

// NO NVI
class DigiPlayer {
    public:
    // BOTH CLIENTS AND SUBCLASSES CAN OVERRIDE AND ACSESS THESE METHODS
    virtual void play(){}
    virtual ~DigiPlayer();
};

class nviDigiPlayer
{
private:
    virtual void doPlay(){}
public:
    void play() { doPlay(); } // client facing wrapper of virtual methods so client cant override
    virtual ~nviDigiPlayer();
};
