class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
       vector<int> res;
        for (int a: nums) {   
            while (true) {   
                int x = gcd(res.empty() ? 1 : res.back(), a);
                if (x == 1) break; // means they are coprime
                a *= res.back() / x;
                res.pop_back();
            }
            res.push_back(a);
        }
        return res;  
    }
};