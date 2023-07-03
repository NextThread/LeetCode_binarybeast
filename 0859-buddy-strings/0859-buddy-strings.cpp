class Solution {
public:
    bool buddyStrings(string A, string B) {
         if (A == B)
            return (set<char>(A.begin(), A.end()).size() < A.size());
        int n = A.length();
        int l = 0, r = n-1;
        
        while(l < n && A[l] == B[l]) // find the index from left where mismatched
            l++;
        while(r >= 0 && A[r] == B[r]) // find the index from right where mismatched
            r--;
        if(l < r)
            swap(A[l], A[r]); // swap
        
        return A == B; // check equal
    }
};