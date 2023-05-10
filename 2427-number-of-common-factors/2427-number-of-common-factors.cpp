class Solution {
public:
    int commonFactors(int a, int b) {
      int cnt = 0;
        for(int i = 1 ; i <= min(a, b) ; i++) {
            cnt += (a%i == 0 and b%i == 0);
        }
        return cnt;
    }
};