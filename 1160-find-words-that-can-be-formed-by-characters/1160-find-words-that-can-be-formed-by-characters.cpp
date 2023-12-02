class Solution {
public:
    int countCharacters(vector<string>& v, string s) {
          map<char,int> m,p;
          int t=0;
        
          for(auto c: s)
               m[c]++;
           
          for(int i=0;i<v.size();i++)
          {   
              p=m;
              bool ok=1;
             
              for(int j=0;j<v[i].size();j++)
              {
                 p[v[i][j]]--; 
                 if(p[v[i][j]]<0)
                 {
                     ok=0;
                     break;
                 }
              }
              if(ok)
                  t+=v[i].size();
          }
        return t;
    }
};