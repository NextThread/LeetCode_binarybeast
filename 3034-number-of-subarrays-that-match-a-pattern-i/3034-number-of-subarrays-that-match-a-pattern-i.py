class Solution(object):
    def countMatchingSubarrays(self, nums, pattern):
        """
        :type nums: List[int]
        :type pattern: List[int]
        :rtype: int
        """
        n=len(nums)
        ans=0
        m=len(pattern)
        
        def valid(arr):
            l=[]
            for i in range(1,len(arr)):
                if arr[i]>arr[i-1]:
                    l.append(1)
                elif arr[i]==arr[i-1]:
                    l.append(0)
                else:
                    l.append(-1)
        
            return l==pattern
                
        
        for i in range(n-m):
            sub=nums[i:i+m+1]
            if valid(sub):
                ans+=1
        
        return ans