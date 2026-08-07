class FreqStack {
private:
    unordered_map<int , int>freq;
    unordered_map<int , vector<int>>group;
    int maxfreq;
public:
    FreqStack() {
        maxfreq = 0;
    }
    
    void push(int val) {
        int f = ++freq[val];

        if(f > maxfreq){
            maxfreq = f;
        }

        group[f].push_back(val);
    }
    
    int pop() {
        int val = group[maxfreq].back();
        group[maxfreq].pop_back();

        freq[val]--;
        if(group[maxfreq].empty()){
            maxfreq--;
        }

        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */