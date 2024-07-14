class Solution {
public:
     long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end());
        sort(v.begin(), v.end());
        long long sumH = 0, sumV = 0, res = 0;
        for (int x : h) sumH += x;
        for (int x : v) sumV += x;

        int i = h.size() - 1, j = v.size() - 1;
        while (i >= 0 && j >= 0) {
            if (h[i] > v[j]) {
                res += h[i] + sumV;
                sumH -= h[i];
                i--;
            } else {
                res += v[j] + sumH;
                sumV -= v[j];
                j--;
            }
        }
        return res + sumH + sumV;
    }
};