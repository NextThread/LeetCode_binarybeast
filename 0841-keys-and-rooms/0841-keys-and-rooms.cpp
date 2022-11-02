class Solution {
public:
  void dfs(vector<vector<int>> &rooms , vector<bool> &visited , int start)    {
        visited[start] = 1;
        for(auto i : rooms[start])
            if(!visited[i])
                dfs(rooms , visited , i);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), 0);        
        int vis = 0;
        dfs(rooms , visited , 0);
        for(auto it : visited) if(it) vis++;
        return rooms.size() == vis;
    }
};