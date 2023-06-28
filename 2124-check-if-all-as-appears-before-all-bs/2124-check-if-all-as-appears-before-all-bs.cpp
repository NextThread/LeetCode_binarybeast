class Solution {
public:
    bool checkString(string s) {
        for(int i = 0 ; i < s.size()-1 ; i++) {
            if(s[i] == 'b' and s[i+1] == 'a') {
                return false;
            }
        }
        return true;
    }
};