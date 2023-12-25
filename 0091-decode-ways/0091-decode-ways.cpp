class Solution {
public:
    int numDecodings(string s) {
        vector<int> hg(s.size()+1,0);
        int ans=0;
        ans = recur(s,0,hg);
        return ans;
    }
    int recur(string s, int pos, vector<int>& hg){
        if(pos==s.size())return 1;
        if(s[pos]=='0')return 0;
        if(pos==s.size()-1)return 1;
        if(hg[pos]>0)return hg[pos];
        string b = s.substr(pos,2);
        
        int way1 = recur(s,pos+1,hg);
        int way2=0;
        if(stoi(b)<=26&&stoi(b)>0){
            way2 = recur(s,pos+2,hg);
        }
        hg[pos]= way1+way2;
        return hg[pos];
    }
};