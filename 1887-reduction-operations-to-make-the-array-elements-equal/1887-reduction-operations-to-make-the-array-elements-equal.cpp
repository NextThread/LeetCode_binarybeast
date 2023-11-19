class Solution {
public:
    int reductionOperations(vector<int>& a) {
         map <int,int> m;
        for(int i: a) m[i]++;
        int i=0, c=0;
        for(auto [x,y]:m) {
            c=c+(y*i);
            i++;
        }   
        return c;
    }
};