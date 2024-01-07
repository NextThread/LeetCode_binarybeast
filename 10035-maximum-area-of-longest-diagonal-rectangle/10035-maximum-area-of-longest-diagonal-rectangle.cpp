class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
      int area = 0, diag = 0;
    for(auto d : dimensions){
        int t = d[0] * d[0] + d[1]*d[1];
        if(t > diag || (t == diag && d[0]*d[1] > area)){
            diag = t;
            area = d[0]*d[1];
        }
    }
    return area;
    }
};