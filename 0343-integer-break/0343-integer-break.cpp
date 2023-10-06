class Solution {
public:
    int integerBreak(int n) {
        return ((n>3)?pow(3,n/3-((n%3)&1))*pow(2,(n+n%3)%3):n-1);
    }
};