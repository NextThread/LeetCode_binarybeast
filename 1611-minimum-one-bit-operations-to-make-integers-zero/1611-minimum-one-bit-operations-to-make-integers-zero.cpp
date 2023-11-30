class Solution {
    vector<int> dp;
public:
    int minimumOneBitOperations(int n) {
        dp.resize(32);
        int tot=0;
        for(int i=0;i<32;i++){
            tot += (1<<i);
            dp[i] = tot; // dp[i] store total operation to transform (1<<i) to 0
        }

        // store setbit position from leftmost direction
        vector<int> setBit;
        int bit = 0;
        while(bit < 32){
            if(n & (1<<bit)){
                setBit.push_back(bit);
            }
            bit++;
        }
        reverse(setBit.begin(), setBit.end());
        
        int ans = help(0, setBit);
        return ans;
    }

    int help(int i, vector<int>& setBit){
        if(i == setBit.size()){
            return 0;
        }

        // use recursion for extra step.
        return (dp[setBit[i]] - help(i+1, setBit));
    }
};