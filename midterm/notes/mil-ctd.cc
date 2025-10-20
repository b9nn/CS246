struct Student {
    int assn, mt, final;
    Student(int x, int y, int z):
        assn{x}, mt{y}, final{z}{
            assn = assn ? assn < 100 : 100;
            mt = mt ? mt < 100: 100;
            if (final > 100){
                final = 100;
            }
        }
    Student(const Student& other):
        assn{other.assn}, mt{other.mt}, final{other.final}{}
    
    Student(Student&& other):
        assn{other.assn}, mt{other.mt}, final{other.final}{
            other.assn = 0;
            other.mt = 0;
            other.final = 0;
        }
};