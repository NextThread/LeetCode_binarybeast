class Solution {
public:
    int numberOfWays(string c) {
         int curSeat=0,curPlant=0;
        long long ans=1;
        for(auto i:c){
            if(i=='S'){curSeat++;}
            if(curSeat==2 && i=='P') curPlant++;
            if(curSeat==3){
                ans*=(curPlant+1);                     //calculating number of ways
                ans=ans%1000000007;
                curPlant=0;
                curSeat=1;
            }
        }
        if(curSeat<2) return 0;           // if last room doesn't have 2 chairs
        return ans;
    }
};