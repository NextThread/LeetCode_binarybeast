class Solution {
public:
    string getPermutation(int n, int k) {
      string s = "";
      for(int i = 1 ; i <= n ; i++) s += to_string(i);
      if(k == 1) return s; // base case: if k is 1, means the original string is the kth permutation, so return the original string
      do{
        next_permutation(s.begin(), s.end());
        k--;
      }
      while(k > 1);
      return s;
    }
};