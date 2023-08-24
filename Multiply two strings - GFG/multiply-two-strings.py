#User function Template for python3

class Solution:
    def multiplyStrings(self,s1,s2):
        # code here
        # return the product string
        sign = 1
        if s1.startswith("-"):
            sign *= -1
            s1 = s1[1:]
        if s2.startswith("-"):
            sign *= -1
            s2 = s2[1:]
   
        def multiply(s1: str, s2: str):
            carry = 0
            r = 0
            d = ord(s2)-ord('0')
            m, n = 1, len(s1)
            for i in range(n-1, -1, -1):
                di = ord(s1[i])-ord('0')
                p = d*di+carry
                carry = p//10
                r += p%10*m
                m *= 10
            r += carry*m
            return r
        
        ans = 0
        m = 1
        for i in range(len(s2)-1, -1, -1):
            ans += multiply(s1, s2[i])*m
            m *= 10
        return ans*sign
        # code here
        # return the product string


#{ 
 # Driver Code Starts
#Initial Template for Python 3

if __name__ == "__main__":
    t=int(input())
    for i in range(t):
        a,b=input().split()
        print(Solution().multiplyStrings( a.strip() , b.strip() ))

# } Driver Code Ends