class Solution {
public:
    int partitionArray(vector<int>& A, int k) {
         sort(A.begin(), A.end());
        int res = 1, mn = A[0], mx = A[0];
        for (int& a: A) {
            mn = min(mn, a);
            mx = max(mx, a);
            if (mx - mn > k) {
                res++;
                mn = mx = a;
            }
        }
        return res;
    }
};