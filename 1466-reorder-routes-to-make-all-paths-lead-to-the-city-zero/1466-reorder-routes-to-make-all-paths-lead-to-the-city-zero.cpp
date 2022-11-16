class Solution {
public: 
     void reorderPaths(int currCity, vector<vector<int>>& adjCities, int& count, vector<bool>& visited)
    {
        visited[currCity] = true;
        for(auto city : adjCities[currCity])
        {
            if(!visited[abs(city)])
            {
                if(city > 0) //reorder the path 
                    count++;
                reorderPaths(abs(city), adjCities, count, visited);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        // for every city store the adjacent city along with direction 
        // to store the direction we use positive indicating a road from a to b for a
        // we use negative indicating there is a road from b to a for a
        vector<vector<int>> adjCities(n);
        vector<bool> visited(n,false);
        for(int i = 0 ; i < connections.size() ; i++)
        {
            int city1 = connections[i][0];
            int city2 = connections[i][1];
            adjCities[city1].push_back(city2);
            adjCities[city2].push_back(-city1);
        }
        //start dfs from city  0 
        //when ever you found a positive then it need to be reversed
        int count = 0;
        reorderPaths(0, adjCities, count, visited);
        return count;
    }
};