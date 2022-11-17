class Solution {
public:
    string getPermutation(int n, int k) {
      
      /*     using STL       */
      
      // string s = "";
      // for(int i = 1 ; i <= n ; i++) s += to_string(i);
      // if(k == 1) return s; // base case: if k is 1, means the original string is the kth permutation, so return the original string
      // do{
      //   next_permutation(s.begin(), s.end());
      //   k--;
      // }
      // while(k > 1);
      // return s;
      
      
     /*  Another method, without stl  + optimized approach  */
    int fact = 1;
    vector<int>nums;
    for(int i = 1 ; i < n ; i++)
    {
        fact *= i;
        nums.push_back(i);
    }
    nums.push_back(n);
    k -= 1;
    string ans = "";
    while(1)
    {
        ans += to_string(nums[k/fact]);
        nums.erase(nums.begin()+k/fact);
        if(nums.size() == 0) break;
        k %= fact;
        fact /= nums.size();
    }
    return ans;
    }
};