class Solution {
public:
    vector<int> p;
    int Mst(int n, vector<vector<int>>& edges, int indexToBeLeft, int edgeCount, int cost){
        for(int edgeIndex = 0; edgeIndex < edges.size(); edgeIndex++){
            if(edgeIndex == indexToBeLeft){
                continue;
            }
            int parent = findParent(edges[edgeIndex][0]);
            int child = findParent(edges[edgeIndex][1]);
            if(parent == child){
                continue;
            }
            p[child] = parent;
            edgeCount++;
            cost += edges[edgeIndex][2];
        }
        
        return edgeCount != n-1 ? INT_MAX : cost;
    }
    
    int findParent(int child){
        if(p[child] == -1){
            return child;
        }
        return p[child] = findParent(p[child]);
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<int> critical, pCritical;
        p.resize(102);
        for(int i = 0; i < 102; i++){
            p[i] = -1;
        }
        map<pair<pair<int,int>,int>,int> prevIndexes;
        map<int,int> locateIndexes;
        for(int i = 0; i < edges.size(); i++){
            prevIndexes[{{edges[i][0], edges[i][1]}, edges[i][2]}] = i; 
        }
        sort(edges.begin(), edges.end(), [](auto &v1, auto &v2){
            return v1[2] < v2[2];
        });
        for(int i = 0; i < edges.size(); i++){
            locateIndexes[i] = prevIndexes[{{edges[i][0], edges[i][1]}, edges[i][2]}]; 
        }
        
        int minSpammingTreeCost = Mst(n, edges, -1, 0, 0);
        for(int i = 0; i < edges.size(); i++){
            for(int j = 0; j <= 101; j++){
                p[j] = -1;
            }
            p[edges[i][1]] = edges[i][0];
            int treeCost = Mst(n, edges, -1, 1, edges[i][2]);
            if(treeCost == minSpammingTreeCost){
                for(int j = 0; j <= 101; j++){
                    p[j] = -1;
                }
                treeCost = Mst(n, edges, i, 0, 0);
                if(treeCost > minSpammingTreeCost){
                    critical.push_back(locateIndexes[i]);
                }
                else{
                    pCritical.push_back(locateIndexes[i]);
                }
            }
        }
        return {critical, pCritical};
    }
};