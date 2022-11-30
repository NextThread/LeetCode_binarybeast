class Solution {
public:
    int compress(vector<char>& chars) {
    int cnt = 1;
    string res;
    for(int i = 0 ; i < chars.size() ; i++)
    {
        while(i<chars.size()-1 && chars[i+1] == chars[i])
        {
            cnt++;
            i++;
        }
        res += chars[i];
        if(cnt == 1)
        {
            continue;
        }
        res += to_string(cnt);
        cnt = 1;
     }
     chars.clear();
     for(int i = 0 ; i < res.size() ; i++)
     {
          chars.push_back(res[i]);
     }
     return chars.size();
    }
};