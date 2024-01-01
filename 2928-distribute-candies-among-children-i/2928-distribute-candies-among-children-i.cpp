class Solution {
public:
    using ll = long long;

    // Function to calculate the number of ways to distribute candies
    ll f(ll n, ll L) {
        // Calculate the minimum and maximum values based on the constraints
        ll minv = std::max(0ll, n - L);
        ll maxv = std::min(n, L);

        // Return the number of ways to distribute candies in the given range
        return std::max(0ll, maxv - minv + 1);
    }

    // Function to calculate the total number of ways to distribute candies
    int distributeCandies(int n, int L) {
        ll ans = 0;

        // Iterate through all possible cases
        for (int i = 0; i <= std::min(n, L); i++)
            ans += f((ll)(n - i), (ll)L);

        // Return the total number of ways to distribute candies
        return (int)ans;
    }
};