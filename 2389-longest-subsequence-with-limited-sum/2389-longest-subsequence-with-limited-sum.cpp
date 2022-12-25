class Solution {
public:
    vector<int> answerQueries(vector<int>& A, vector<int>& queries) {
      sort(A.begin(), A.end());
        vector<int> res;
        for (int i = 1; i < A.size(); ++i) A[i] += A[i - 1]; // update A into prefix array
        for (int q: queries)
            res.push_back(upper_bound(A.begin(), A.end(), q) - A.begin()); // binary search
        return res;
    }
};