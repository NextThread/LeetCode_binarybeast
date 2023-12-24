class Solution {
public:
    int minOperations(string s) {
    int f1 = 1, f0 = 0, cnt1 = 0, cnt2 = 0;
    for (auto ch : s) {
        cnt1 += ch - '0' != f1;
        cnt2 += ch - '0' != f0;
        swap(f1, f0);
    }
    return min(cnt1, cnt2);
}
};