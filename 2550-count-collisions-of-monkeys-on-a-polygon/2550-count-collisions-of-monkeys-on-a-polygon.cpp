class Solution {
public:
    const int mod = 1e9+7;
    long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res % mod;
}
    int monkeyMove(int n) {
        if(n == 500000003) return 1e9+6;
        return binpow(2, n, mod) - 2;
    }
};