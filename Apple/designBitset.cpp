class Bitset {
    unordered_set<int>zeroes;
    unordered_set<int>ones;
    int sz;
public:
    Bitset(int size) {
        sz = size;
        for(int i = 0 ; i < sz ; i++){
            zeroes.insert(i);
        }
    }
    
    void fix(int idx) {
        if(zeroes.find(idx) != zeroes.end()){
            zeroes.erase(idx);
        }
        ones.insert(idx);
    }
    
    void unfix(int idx) {
        if(ones.find(idx) != ones.end()){
            ones.erase(idx);
        }
        zeroes.insert(idx);
    }
    
    void flip() {
        swap(zeroes,ones);
    }
    
    bool all() {
        return zeroes.size() == 0;
    }
    
    bool one() {
        return ones.size() > 0;
    }
    
    int count() {
        return ones.size();
    }
    
    string toString() {
        string res = "";
        for(int i = 0 ; i < sz; i++){
            if(ones.find(i) != ones.end()){
                res += "1";
            }
            else{
                res += "0";
            }
        }
        return res;
    }
};
