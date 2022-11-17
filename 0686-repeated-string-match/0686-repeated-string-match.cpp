class Solution {
public:
    int repeatedStringMatch(string a, string b) { 
      
        // easy to understand code
      
        string s = "";
        int cnt = 0;
        while(s.size() < b.size()) // keep adding copy of a
        {
            s += a;
            cnt++;
        }
        if(s.find(b) != string::npos)
            return cnt;
        s += a;
        cnt++;
        if(s.find(b) != string::npos)
            return cnt;
        
        return -1; 
      
        // string res = a;
        // for(int i = 1 ; i <= b.length()/a.length()+2 ; i++){
        //     if(res.find(b) != string::npos) return i;
        //     res += a;
        // }
        // return -1;
      
    
    }
};