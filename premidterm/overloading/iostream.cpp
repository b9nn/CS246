struct Grade{
    int theGrade;
};

Grade me{100};

ostream& operator<<(ostream& out, const Grade& g){
    out << g.theGrade << "%";
    return out;
}

// sample calling
cout << me;
ofs << me;
oss << me;


// NOW FOR INPUT
istream& operator>>(istream& in, Grade & g){
    in >> g.theGrade;
    if (g.theGrade < 0){
        g.theGrade = 0
    }
    else if (g.theGrade > 100){
        g.theGrade = 100
    }
    return in;
}

Grade myGrade;
cin >> myGrade;
