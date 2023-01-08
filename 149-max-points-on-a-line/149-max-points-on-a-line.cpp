class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
       int result = 0;
        for(int i = 0 ; i < points.size() ; ++i) {
            unordered_map <long double, int> h;
            int same = 1, localmax = 0;
            for(int j = i+1 ; j < points.size() ; ++j) {
                if(points[i][0] == points[j][0] && points[i][1] == points[j][1]) same++; // both are on same point
                else if(points[i][0] == points[j][0]) h[INT_MAX]++; // both are on same line
                else{
                    long double slope = (long double)(points[i][1] - points[j][1]) / (long double)(points[i][0] - points[j][0]);
                    h[slope]++; // increase the counter for the slope
                }
            }
            for(auto i : h) localmax = max(localmax, i.second); // pickup the max slope count
            localmax +=same; // add those points that are at same point
            result = max(result, localmax); // update the result
        }
        return result;
    }
};