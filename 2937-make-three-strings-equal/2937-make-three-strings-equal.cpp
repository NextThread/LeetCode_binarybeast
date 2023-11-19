class Solution {
public:
    int findMinimumOperations(string s1, string s2, string s3) {
        int i = 0, j = 0, k = 0;
        int cnt = 0;
        while(i < s1.size() and j < s2.size() and k < s3.size() and s1[i] == s2[j] and s2[j] == s3[k]) {
            cnt++;
            i++;
            j++;
            k++;
        }
        return (cnt == 0) ? -1 : (s1.size()+s2.size()+s3.size()-3*cnt);
    }
};