class compare{
  public:
    bool operator()(vector<int> a, vector<int> b){
        return a[2] > b[2];
    }
};
class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{0, 1}, {0 , -1}, {1,0} , {-1, 0}};
        
        priority_queue<vector<int> , vector<vector<int>> , compare> pq;
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<bool>> visited(n, vector<bool>(m,false));
        
        pq.push({0 ,0 , 0});
        
        while(!pq.empty()){
            
            vector<int> t = pq.top();
            pq.pop();
            
            int i = t[0];
            int j = t[1];
            int cost = t[2];
            
            if( i == n-1 && j == m-1) return cost; // we did reached at last index
            if(visited[i][j]) continue;
            visited[i][j] = true;
            
            for(int d = 1; d <= 4; d++){ // generate directions
                int x = i + dir[d-1][0];
                int y = j + dir[d-1][1];
                if( x >= 0 && y >= 0 && x < n && y < m && !visited[x][y] ){ 
                    if(d == grid[i][j]) pq.push({x,y,cost});
                    else pq.push({x,y,cost+1});
                }
            }
        }
        return -1;
    }
};
