class Solution {
public:
    
    int getKth(int lo, int hi, int k) {
      vector<pair<int, int>> vp;
        for(int i = lo ; i <= hi ; i++) {
            int num = i;
            int pow = 0;
            while(num > 1) {
                if(num % 2 == 1) num = num*3+1;
                else num = num/2;
                pow++;
            }
            vp.push_back(make_pair(pow, i));
        }
        sort(vp.begin(), vp.end());
        return vp[k-1].second;
    }
};