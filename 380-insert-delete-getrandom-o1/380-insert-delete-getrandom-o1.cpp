class RandomizedSet {
public:
    unordered_set<int> st;
    RandomizedSet() { }
    
    bool insert(int val) {
        if(!st.count(val)) {
            st.insert(val);
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        if(st.count(val))
        {
            st.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        vector<int> a;
        for(auto it : st) a.push_back(it);
        return a[(rand() % a.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */