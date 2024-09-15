#include <vector>
#include <queue>
#include <climits>
#include <cstring>
using namespace std;

int dp[50][50][50][50]; 
int disx[8] = {1, 2, 2, 1, -1, -2, -2, -1}; 
int disy[8] = {2, 1, -1, -2, -2, -1, 1, 2}; 

void bfs(int startx, int starty) {
    queue<pair<pair<int, int>, int>> q; 
    q.push({{startx, starty}, 0});
    dp[startx][starty][startx][starty] = 0; 

    while(!q.empty()) {
        int x = q.front().first.first; 
        int y = q.front().first.second; 
        int d = q.front().second; 
        q.pop();

        for(int i = 0; i < 8; i++) {
            int nextx = x + disx[i]; 
            int nexty = y + disy[i]; 
            if(nextx >= 0 && nextx < 50 && nexty >= 0 && nexty < 50 && dp[startx][starty][nextx][nexty] == -1) {
                dp[startx][starty][nextx][nexty] = 1 + d; 
                q.push({{nextx, nexty}, d + 1}); 
            }
        }
    }
}


class Solution {
public:
    void dist_cal() {
    static bool flag = false; 
    if(flag) return; 
    memset(dp, -1, sizeof(dp)); 
    for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 50; j++) {
            if(dp[i][j][i][j] == -1) bfs(i, j);
        }
    }
    flag = true; 
}
    vector<vector<int>> memo;
    int f(int curr, int mask, int turn, vector<vector<int>>& positions) {
        int n = positions.size();
        if(mask == (1 << n) - 1) return 0;
        if(memo[curr][mask] != -1) return memo[curr][mask]; // check memo

        int res;
        int x = positions[curr][0]; 
        int y = positions[curr][1]; 

        if(!turn) { // alci move
            res = INT_MIN; 
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) continue; 
                int nextx = positions[i][0]; 
                int nexty = positions[i][1]; 
                int newDist = dp[x][y][nextx][nexty]; 
                res = max(res, newDist + f(i, mask | (1 << i), !turn, positions));
            }
        } else { // bob move
            res = INT_MAX; 
            for(int i = 0; i < n; i++) {
                if(mask & (1 << i)) continue; 
                int nextx = positions[i][0]; 
                int nexty = positions[i][1]; 
                int newDist = dp[x][y][nextx][nexty]; 
                res = min(res, newDist + f(i, mask | (1 << i), !turn, positions));
            }
        }

        return memo[curr][mask] = res; // memo
    }


    int maxMoves(int kx, int ky, vector<vector<int>>& positions) {
        positions.push_back({kx, ky}); 
        int n = positions.size(); 
        dist_cal(); 
        memo.resize(n, vector<int>(1 << n, -1)); 
        return f(n-1, (1<<(n-1)), 0, positions); 
    }
};