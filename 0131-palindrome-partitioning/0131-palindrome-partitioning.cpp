class Solution {
public:
    bool isPalindrome(string s, int i, int j) {
        while(i < j) {
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    void solve(int ind,int n,string s,vector<vector<string>>& ans,vector<string>& temp) {
        if(ind == n) {
            ans.push_back(temp);
            return;
        }
        for(int i = ind ; i < n ; i++) {
            if(isPalindrome(s, ind, i)) {
                temp.push_back(s.substr(ind, i-ind+1));
                solve(i+1, n, s, ans, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(0, s.length(), s, ans, temp);
        return ans;
    }
};