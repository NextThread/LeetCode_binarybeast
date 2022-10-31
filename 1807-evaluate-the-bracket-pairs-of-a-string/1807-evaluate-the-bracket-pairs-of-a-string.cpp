class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
     map<string, string>mp;
      for(auto it : knowledge)
      {
        mp[it[0]] = it[1]; // storing knowledge[0] value with their corresponding knowledge[1]
      }
      string res = ""; // the string that we will return in ans
      for(int i = 0 ; i < s.length() ; i++)
      {
        bool take = false; // take = false, we will use it to check if we don't have any key value present in our map
        int add = -1;
       if(s[i] == '(') // if we encountered the closing brace then till we got the opening brace ) we need to store the string, which we are going to search in our map
       {
         string test = ""; // this string will be used to store every string that are inside ()
         int temp = i+1; // the index from which we are going to store the string after encountering '('
         while(s[temp] != ')') // till we dont get ) we need to traverse for the string
         {
           test += s[temp++]; // keep adding the characters in the string && increase the index by 1
         }
         take = true; // if we did the operation then we are chaning this to true, because at last we have to check this
         add = temp; // now store the last traversed index in a variable, because we need to replace i by this, as we have already traversed the previous indexes
         if(mp.find(test) != mp.end()) res += mp[test]; // check if we have the string present in out map, then add the string
         else res += '?'; // else add ? in place of (string that are not in the map), as mentioned in problem statement
       }
        else res += s[i]; // else keep adding the remaining characters
        if(add != -1) i = add; // if the first operation we have done, then we have to set the i position to the index where we have traversed just right now, so set i to that index(add)
      }
      return res; // atlast return the resultant string
    }
};