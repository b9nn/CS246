#include <memory>
class c {
    std::unique_ptr<int> data;
    pulic:
        std::unique_ptr<int>& getData() {return data;}
};

c myC;
std::unique_ptr<int>& refC = myC.getData(); // Works!, doesnt trasfer ownership, jsut exposes our data
