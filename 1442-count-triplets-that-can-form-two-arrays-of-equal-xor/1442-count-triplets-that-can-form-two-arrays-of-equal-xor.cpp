class Solution {
public:
    int countTriplets(vector<int>& arr) {
         map<int, vector<int>> xorMap;
        xorMap[0].push_back(-1);
        
        int x = 0;
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            x ^= arr[i];
            for (auto j: xorMap[x]) {
                int start = j + 1, end = i;
                ans += end - start;
            }
            xorMap[x].push_back(i);
        }
        
        return ans;
    }
};