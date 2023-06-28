class Solution {
public:
    int numTeams(vector<int>& rating) {
         int ans = 0;
        for(int i=1;i<rating.size()-1;++i){
            int l=0,r=0;
            for(int j=0;j<i;++j)
                if(rating[j]<rating[i]) l++;
            for(int j=i+1;j<rating.size();++j)
                if(rating[j]>rating[i]) r++;
            ans += l*r+(i-l)*(rating.size()-i-r-1);
        }
        return ans;
    }
};