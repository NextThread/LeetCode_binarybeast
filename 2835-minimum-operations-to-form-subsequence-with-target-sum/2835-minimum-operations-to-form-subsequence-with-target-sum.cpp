class Solution {
public:
    int minOperations(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        long long sum=0;
        map<long,long> m;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            m[nums[i]]++;
        }
        if(sum<target)
            return -1;
        if(sum==target)
            return 0;
        bitset<31> nx(target);
        int count=0;
        sum=0;
      for(int i=31;i>=0;i--)
      {
          if(nx[i]==1)
          {
              int x=pow(2,i);
            m[x]--;
          }
      }
    for(auto i:m)
    {
       if(i.second>=2)
       {  m[i.first*2]+=i.second/2;
       }
        if(i.second<0)
        {
            m[i.first]+=2;
            m[i.first*2]--;
            count++;
        }
            }
       

            
     return count;   
    }
};