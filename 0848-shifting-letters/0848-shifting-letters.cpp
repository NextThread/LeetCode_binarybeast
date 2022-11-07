class Solution {
public:

    string shiftingLetters(string s, vector<int>& shifts) {
       long long sum = 0;
      for(auto it : shifts)
      {
        sum += (long long)it; // if we use accumulate(shifts.begin(), shifts.end(), 0) , it gives TLE
      }
        for(int i = 0 ; i < s.size() ; i++)
        {
            s[i] = (s[i]-'a' + sum)%26+97;
            sum -= shifts[i];
        }
        return s;
    }
};

//  abc
//  dbc
//  igc
//  rpl