//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

const int dir[4][2] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
class Solution {
public:
	int numberOfEnclaves(vector<vector<int>>& grid) noexcept {
		const int n = grid.size(), m = grid[0].size();
		function<void(const int, const int)> dfs = [&](const int x, const int y) {
			grid[x][y] = 0;
			for (auto& d : dir) {
				const int i = x + d[0], j = y + d[1];
				if ((i >= 0) && (i < n) && (j >= 0) && (j < m) && grid[i][j]) dfs(i, j);
			}
		};
		for (int i = 0; i < n; ++i) {
			if (grid[i][0]) dfs(i, 0);
			if (grid[i][m - 1]) dfs(i, m - 1);
		}
		for (int j = m - 2; j > 0; --j) {
			if (grid[0][j]) dfs(0, j);
			if (grid[n - 1][j]) dfs(n - 1, j);
		}
		return accumulate(grid.cbegin(), grid.cend(), 0, [](auto lhs, const auto& rhs) {
			return accumulate(rhs.cbegin(), rhs.cend(), lhs);
		});
	}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends