class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 0) return false;
        return ((n-1)&n)==0 and (n-1)%3==0; // should be power of 2 and n-1 should be divisible by 3
    }
};