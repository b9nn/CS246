struct Node{
    int data;
    Node *next;
    Node& operator=(const Node& other){
        data = other.data;
        delete next; // clean-up old memory
        next = other.next ? new Node{*other.next} : nullptr; // if other.next then other.next, if not nullptr
        return *this;
    }
};

Node n{1, new Node {2, nullptr}};
n = n; // self-assn, but we deleted memory


// SAFE OPTIONS
struct Node{
    int data;
    Node *next;
    Node& operator=(const Node& other){
        if (this == &other){
            return *this;
        }
        Node *temp = next;
        data = other.data;
        next = other.next ? new Node{*other.next} : nullptr; // this is the money line
        delete temp;
        return *this;
    }
};




export struct Vec {
    int dimension; // The number of dimensions; must be non-negative 
    int *values;   // The data

    // YOU HAVE TO ADD ALL MEMBER FUNCTION DECLARATIONS HERE
    Vec(int dim = 0, int* vectors = nullptr):
        dimension{dim}, values{vectors}{};
    
    int length(){
        int total = 0;
        for (int i = 0; i < this->dimension; ++i){
            int curr = this->values[i] > 0 ? this->values[i] : -1 * this->values[i];
            total += curr; 
        }
        return total;
    }
    Vec operator+(const Vec& v){
        int* vals = new int[this->dimension];
        for (int i = 0; i < this->dimension; ++i){
            vals[i] = values[i] + v.values[i];
        }
        Vec res = Vec(dimension, vals);
        return res;
    }

    void operator-(){
        for (int i = 0; i < this->dimension; ++i){
            this->values[i] *= -1;
        }
    }
    Vec& operator<<(const int scalar){
        for (int i = 0; i < this->dimension; ++i){
            this->values[i] *= scalar;
        }
        return *this;
    }
};

// YOU HAVE TO ADD ALL NON-MEMBER FUNCTION DECLARATIONS HERE
ostream& operator<<(ostream& out, const Vec& vector){
    out << '[';
    for (int i = 0; i < vector.dimension; ++i){
        out << vector.values[i];
        if (i != (vector.dimension - 1)){
            out << ', ';
            
        }
    }
    out << ']';
    return out;
}