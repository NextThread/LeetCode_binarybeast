class Solution {
public:
    int minimumSubarrayLength(vector<int>& a, int k) {
          int ans=INT_MAX;
        for(int i=0;i<a.size();i++){
            int p=a[i];
            int sum=1;
            if(p>=k)ans=1;
            for(int j=i+1;j<a.size();j++){
                p|=a[j];sum++;
                if(p>=k){ans=min(sum,ans);break;}
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};