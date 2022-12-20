class Solution {
public:
  
  // Idea is simple, we just need to do dfs, after applying dfs for all nodes, check if any node has not been visited, if no of visited cell == room, then true else false
  
  void dfs(vector<vector<int>> &rooms , vector<bool> &visited , int start)    {
        visited[start] = 1;
        for(auto i : rooms[start])
            if(!visited[i])
                dfs(rooms , visited , i);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited( rooms.size() );        
        dfs(rooms , visited , 0);
        return rooms.size() == count(visited.begin() , visited.end() , 1);
    }
};