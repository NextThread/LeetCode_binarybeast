class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        if(f.size() == 1 and f[0] == 0) return true;
        if(f[0] == 0 and f[1] == 0) {
            f[0] = 1;
            n--;
        }
        if(f[f.size()-1] == 0 and f[f.size()-2] == 0) {
            f[f.size()-1] = 1;
            n--;
        }
        for(int i = 1 ; i < f.size()-1 ; i++) {
            if(f[i] == 0) {
                if(f[i-1] == 0 and f[i+1] == 0) {
                    n--;
                    f[i] = 1;
                }
            }
            if(n == 0) return true;
        }
        return n <= 0;
    }
};