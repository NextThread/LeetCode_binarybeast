class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
         auto is_even = [] (auto e) { return e % 2 == 0; };
    partition (A.begin (), A.end (), is_even);
    return A;
    }
};