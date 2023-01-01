class Solution {
public:
    int countDigits(int num) {
       int cnt = 0;
        for (auto ch : to_string(num))
            cnt += (num % (ch - '0') == 0);
        return cnt;
    }
};