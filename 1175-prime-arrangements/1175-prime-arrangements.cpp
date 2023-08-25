class Solution {
public:
    int hell=1000000007;
    long long fact(long long n)
    {
        if(n==0 || n==1) return 1;
        return ((n%hell)*(fact(n-1)%hell))%hell;
    }
    int numPrimeArrangements(int n) 
    {
        vector<int> sieve(n+1, -1);
        sieve[1] = 1;
        for(int i=2; i*i<=n; i++)
        {
            for(int j=i+i; j<=n; j+=i)
            {
                sieve[j] = 1;
            }
        }
        long long prime=0, notPrime=0;
        for(int i=1; i<=n; i++)
        {
            (sieve[i]==-1)?prime++:notPrime++;
        }
        prime = fact(prime)%hell;
        notPrime = fact(notPrime)%hell;
        int ans=(prime*notPrime)%hell;
        return ans;
    }
};