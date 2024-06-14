class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
         int s = A.size();
        int res=0;
        if (s<2)  return 0;
        sort(A.begin(),A.end());        
        for (int i=1; i<s; ++i) {
            if (A[i]<=A[i-1]){
                res+=A[i-1]+1 -A[i];
                A[i]= A[i-1]+1;
            }
        }
        return res;
    }
};