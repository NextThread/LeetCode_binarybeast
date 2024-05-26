class Solution{
public :
    
    int maxPoints(vector<vector<int>>& points) 
    {
        if(points.size()<=2) return points.size();
        int res=0;
        int n=points.size();
        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];    

                // double slope = double(y2 - y1)/double(x2 - x1);
                int total=2;
                for(int k=0;k<n && k!=i && k!=j;k++){
                    
                    int x = points[k][0];
                    int y = points[k][1];
                    // third point
                    // double(y - y1)/double(x1 - x1)
                    if((y2 - y1)*(x - x1) == (x2 - x1)*(y - y1))
                        total++;
                }
                res = max(res, total);
            }
        }
        return res;
    }
};