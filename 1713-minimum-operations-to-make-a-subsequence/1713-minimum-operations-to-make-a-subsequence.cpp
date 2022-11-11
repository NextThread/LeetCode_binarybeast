class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
    unordered_map<int, int> m;
    vector<int> stack;
    for (auto t : target) m[t] = m.size(); // store all these in the map
    for (auto n : arr) 
    {
        auto it = m.find(n);
        if (it != end(m)) // if it is present in out map
        {
            if (stack.empty() || stack.back() < it->second) // till stack isn't empty or stack.back() < it.second
                stack.push_back(it->second); // keep pushing
            else
                *lower_bound(begin(stack), end(stack), it->second) = it->second; // make the it.second to its lower bound
        }
    }
    return target.size() - stack.size();
    }
};