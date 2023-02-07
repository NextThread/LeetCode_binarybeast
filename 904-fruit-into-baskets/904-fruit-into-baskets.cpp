class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int>mp;
        int i = 0, j = 0, res = 0;
        while(j < fruits.size()) {
            mp[fruits[j]] += 1;
            while(mp.size() > 2) {
                if(mp[fruits[i]] == 1) mp.erase(fruits[i]);
                else mp[fruits[i]] -= 1;
                i++;
            }
            res = max(res, j-i+1);
            j++;
        }
        return res;
    }
};