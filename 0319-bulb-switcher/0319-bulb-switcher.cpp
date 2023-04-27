class Solution {
public:
    int bulbSwitch(int n) {
    int cnt = 0;
    for (int i = 1 ; i*i <= n ; i++) cnt++;
    return cnt;
    }
};