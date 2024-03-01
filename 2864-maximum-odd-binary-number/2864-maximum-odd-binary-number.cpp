class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int one = 0;
        for(char ch : s) one += (ch == '1');
        int fill = one-1;
        string res = "";
        while(fill--) {
            res += '1';
        }
        int zero = s.size()-one;
        while(zero--) {
            res += '0';
        }
        res += '1';
        return res;
    }
};