class Solution {
public:
      int longestPalindrome(vector<string>& words) {
        
        
        // we may have 2 types of words->
        //  1. If both the characters of the word is equal
        //  2. If both are different
        
      map<string, int> mp;
      int nonpair = 0;
      int res = 0;
      for (string word : words) {
         if (word[0] == word[1]) { // if both are equal
             if (mp[word] > 0) { // if its count > 0 
                 nonpair--;
                 mp[word]--;
                 res += 4; // because in this case we are going to use the word 2*times
             }
             else {
                 mp[word]++;
                 nonpair++;
             }
         }
         else {
             string check = word; // now here we're going to check for the string which have different characters in it
             reverse(begin(check), end(check));
             if (mp[check] > 0) {
                 res += 4;
                 mp[check]--;
             }
             else mp[word]++;
         }
     }
      if (nonpair > 0) res += 2;
      return res;
     }
};