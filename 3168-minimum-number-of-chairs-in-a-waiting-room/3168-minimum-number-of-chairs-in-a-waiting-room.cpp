class Solution {
public:
    int minimumChairs(string s) {

        int res=INT_MAX;

        int sum=0;

        for(auto c: s){
            if(c=='E')
            sum-=1;
            else
            sum+=1;
            res=min(res, sum);
        }

        return abs(res);
        
    }
};