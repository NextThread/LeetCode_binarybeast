class OrderedStream {
public:
    vector<string> s;
    int ptr = 1;
    OrderedStream(int n) : s(n + 1) 
    {
        
    }
    vector<string> insert(int id, string value) 
    {
    s[id] = value;
    vector<string> res;
    while (ptr < s.size() && !s[ptr].empty())
        res.push_back(s[ptr++]);
    return res;
}
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */