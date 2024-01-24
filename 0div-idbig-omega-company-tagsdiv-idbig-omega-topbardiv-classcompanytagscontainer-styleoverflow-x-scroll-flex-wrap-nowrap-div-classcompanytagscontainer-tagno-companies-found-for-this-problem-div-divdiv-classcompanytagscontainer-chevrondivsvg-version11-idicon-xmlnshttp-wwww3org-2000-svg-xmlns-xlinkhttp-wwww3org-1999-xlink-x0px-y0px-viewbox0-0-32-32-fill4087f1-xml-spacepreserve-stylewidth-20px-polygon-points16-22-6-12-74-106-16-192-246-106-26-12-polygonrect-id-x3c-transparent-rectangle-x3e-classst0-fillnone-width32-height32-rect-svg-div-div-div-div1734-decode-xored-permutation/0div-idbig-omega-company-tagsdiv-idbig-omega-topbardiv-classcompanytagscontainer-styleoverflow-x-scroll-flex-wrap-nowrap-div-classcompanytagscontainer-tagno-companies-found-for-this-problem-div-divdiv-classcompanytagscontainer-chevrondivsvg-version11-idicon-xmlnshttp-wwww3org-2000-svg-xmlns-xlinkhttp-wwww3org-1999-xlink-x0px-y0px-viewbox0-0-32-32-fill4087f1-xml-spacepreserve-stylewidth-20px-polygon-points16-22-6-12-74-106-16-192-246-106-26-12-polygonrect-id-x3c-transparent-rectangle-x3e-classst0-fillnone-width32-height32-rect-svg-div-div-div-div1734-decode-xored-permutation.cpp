class Solution {
public:
    vector<int>original;
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size() + 1 ;
        int totalXOR = 0 ;
        for(int i = 1 ; i <= n  ;++i ) totalXOR ^= i ;
        for(int i = 1 ; i < encoded.size(); i += 2) totalXOR ^= encoded[i] ; ///take XOR with odd indices
        int a = totalXOR ; //first element of the original array 
        original.push_back(a) ;
        for(auto x : encoded) original.push_back(original.back() ^ x) ;
        return original;
    }
};