class Solution {
public:
    vector<int> findIndices(vector<int>& A, int d, int v) {
       int mini = 0, maxi = 0, n = A.size();
        for (int i = d; i < n; i++) {
            if (A[i - d] < A[mini]) mini = i - d;
            if (A[i - d] > A[maxi]) maxi = i - d;
            if (A[i] - A[mini] >= v) return {mini, i};
            if (A[maxi] - A[i] >= v) return {maxi, i};
        }
        return { -1, -1};   
    }
};