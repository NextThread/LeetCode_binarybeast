class Solution {
public:
    //Time: O(m*n), Space: O(m*n);
    int minDistance(string word1, string word2) {
        int m = word1.length(), n = word2.length();
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        return editDistance(word1, word2, m, n, memo);
    }
    
    int editDistance(string& word1, string& word2, int m, int n, vector<vector<int>>& memo){
        if(m == 0) return memo[m][n] = n;
        if(n == 0) return memo[m][n] = m;
        
        if(memo[m][n] != -1)
            return memo[m][n];
        
        if(word1[m-1] == word2[n-1]) 
            return memo[m][n] = editDistance(word1, word2, m-1, n-1, memo);
        else{
            int insertChar = editDistance(word1, word2, m, n-1, memo);
            int deleteChar = editDistance(word1, word2, m-1, n, memo);
            int replaceChar = editDistance(word1, word2, m-1, n-1, memo);
            
            return memo[m][n] = 1 + min({insertChar, deleteChar, replaceChar});
        }
    }
};