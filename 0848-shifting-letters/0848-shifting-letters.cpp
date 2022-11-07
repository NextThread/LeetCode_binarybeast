class Solution {
public:

    string shiftingLetters(string s, vector<int>& shifts) {
       int n = s.size();
       long long sum = 0;
      for(auto it : shifts)
      {
        sum += (long long)it;
      }
        for(int i = 0 ; i < n ; i++)
        {
            s[i] = (s[i]-'a'+sum)%26+97;
            sum -= shifts[i];
        }
        return s;
    }
};

//  abc
//  dbc
//  igc
//  rpl