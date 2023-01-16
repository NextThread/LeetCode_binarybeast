class Solution {
public:
    
    bool ispalindrome(const string &s)
    {
        int L = 0, R = s.length()-1;
        while(L <= R)
        {
            if(s[L] != s[R]) return false;
            L++;
            R--;
        }
        return true;
    }
    
    int good(int x, string s)
    {
        for(int L = 0 ; L + x <= s.length() ; L++)
        {
            if(ispalindrome(s.substr(L, x))) return L;
        }
        return -1;
    }
    
    string longestPalindrome(string s) {
        int best_len = 0;
        string best_str = "";
        int n = s.length();
        for(int parity : {0, 1})
        {
            int lo = 1, hi = n;
            if(lo%2 != parity) lo++;
            if(hi%2 != parity) hi--;
            while(lo <= hi)
            {
                int mid = (lo+hi)>>1;
                if(mid%2 != parity) mid++;
                if(mid > hi) break;
                int temp = good(mid, s);
                if(temp != -1)
                {
                    if(mid > best_len)
                    {
                        best_len = mid;
                        best_str = s.substr(temp, mid);
                    }
                    lo = mid+2;
                }
                else{
                    hi = mid-2;
                }
            }
        }
        return best_str;
    }
};
