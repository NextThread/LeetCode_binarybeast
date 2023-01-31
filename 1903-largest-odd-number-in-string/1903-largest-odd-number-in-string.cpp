class Solution {
public:
    string largestOddNumber(string num) {
        cout << num.substr(0, 1);
        for(int i = num.length()-1 ; i >= 0 ; i--)
        {
            int dig = num[i]-'0';
            if(dig&1) return num.substr(0, i+1);
        }
        return "";
    }
};