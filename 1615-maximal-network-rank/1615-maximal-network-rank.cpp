class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n,0) ;
        set<vector<int>> connections(begin(roads),end(roads)) ;
        for(auto &x : roads){
            ++degree[x[0]] ;
            ++degree[x[1]] ;
        }
        
        int maxRank = 0 ;
        for(int i = 0 ; i < n ; ++i ){
            for(int j = i + 1 ; j < n ; ++j ){
                int sum = degree[i] + degree[j] ;
                //if they are directly connected then decrease 
                if(connections.find({i,j}) != end(connections) || connections.find({j,i}) != end(connections)) --sum ;
                maxRank = max(maxRank,sum) ;
            }
        }
        
        return maxRank ;
    }
};