class Solution {
public:
    bool judgeSquareSum(int c) {
        
        //brute force // gives tle O(N*N)
        
        // for(int i = 0 ; i <= c ; i++)
        // {
        //     for(int j = 0 ; j <= c ; j++)
        //     {
        //         if((i*i)+(j*j) == c) return true;
        //     }
        // }
        // return false;
        
        
        //  optimized  O(N) or less than N --->sqrt(n)
        
        if(c < 3) return true;
        long long a = 0, b = sqrt(c);
        
        while(a <= b)
        {
            if((long long)(a*a) + (b*b) == c) return true;
            
            else  if((long long)(a*a)+(b*b) < c) a++;
            
            else b--;
        }
        return false;
    }
};