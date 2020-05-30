class CustomStack {
private:
    vector<int> elem;
    int capacity;
public:
    CustomStack(int maxSize) {
        capacity = maxSize;
    }
    
    void push(int x) {
        if (elem.size() < capacity) elem.push_back(x);
    }
    
    int pop() {
        if (!elem.empty()) {
            int res = elem[elem.size()-1];
            elem.pop_back();
            return res;
        }
        return -1;
    }
    
    void increment(int k, int val) {
        int _size = elem.size();
        for (int i=0; i<min(k, _size); i++) elem[i]+=val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */