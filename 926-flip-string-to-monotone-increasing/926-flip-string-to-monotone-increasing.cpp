class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int count1 = 0, count0 = 0;
        for(char ch : s)
        {
            (ch == '1') ? count1++ : count0++;
            count0 = min(count1, count0);
        }
        return count0;
    }
};