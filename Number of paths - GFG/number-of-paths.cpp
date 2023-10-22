//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
class Solution
{
public:
    int numberOfPaths(int rows, int columns) {
        // Initialize the number of paths to 1
        long long numPaths = 1;
        
        // Define a constant for modulo operation
        const int MOD = 1000000007;
        
        // Calculate the number of paths using Combinatorics
        for (int i = 0; i < rows - 1; i++) {
            // Use Combinatorics to calculate C(i + n, i)
            numPaths = (numPaths * (i + columns)) % MOD;
            
            // Use the modular inverse to calculate C(i + 1, i)
            long long temp = modInverse(i + 1, MOD);
            numPaths = (numPaths * temp) % MOD;
        }
        
        return numPaths;
    }

private:
    long long modInverse(long long a, long long m) {
        long long m0 = m;
        long long x0 = 0;
        long long x1 = 1;
        
        if (m == 1)
            return 0;
        
        while (a > 1) {
            // q is quotient
            long long q = a / m;
            long long t = m;
            
            // m is remainder now; process same as Euclid's algorithm
            m = a % m;
            a = t;
            t = x0;
            
            // Update x0 and x1
            x0 = x1 - q * x0;
            x1 = t;
        }
        
        // Make x1 positive
        if (x1 < 0)
            x1 += m0;
        
        return x1;
    }
};


//{ Driver Code Starts.

 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int N, M;
		cin>>M>>N;
		Solution ob;
	    cout << ob.numberOfPaths(M, N)<<endl;
	}
    return 0;
}
// } Driver Code Ends