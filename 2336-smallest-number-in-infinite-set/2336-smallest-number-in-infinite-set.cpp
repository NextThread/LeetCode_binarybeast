class SmallestInfiniteSet {
public:
    int cur = 1;
    set<int> st; 
    int popSmallest() {
        if (!st.empty()) {
            int res = *st.begin();
            st.erase(st.begin());
            return res;
        }
        return cur++;
    }
    void addBack(int num) {
        if (num < cur)
            st.insert(num);
    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */