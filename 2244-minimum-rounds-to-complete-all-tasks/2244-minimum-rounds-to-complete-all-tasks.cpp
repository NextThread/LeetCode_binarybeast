class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int>mp;
        for(int x : tasks) mp[x]++;
        for(auto it : mp) if(it.second < 2) return -1;
        int cnt = 0;
        for(auto it : mp)
        {
            if(it.second == 2)
            {
                it.second -= 2;
                cnt++;
            }
            else if(it.second == 3)
            {
                it.second -= 3;
                cnt++;
            }
            else{
                while(it.second > 3)
                {
                    it.second -= 3;
                    cnt++;
                }
                if(it.second > 0) cnt++;
            }
        }
        return cnt;
    }
};