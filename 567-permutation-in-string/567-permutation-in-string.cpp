class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        /*
         "Permutation doesn't care about the ORDER of the characters"
         "So play with characters FREQUENCY"
        */
        if(s1.size() > s2.size()) return false; // substring should be either same size or smaller but not bigger than original
        vector<int> w(26,0), h(26,0); // to store the frequency of chars of s1 and s2
        for(int i = 0 ; i < s1.size() ; i++)
        {
            w[s1[i]-'a']+=1; // frequency storing for s1
            h[s2[i]-'a']+=1; // frequency storing for s2
        }
        if(w == h) return true; // check if both the frequency array is equal, means it matched our condition
         for (int i = s1.length() ; i < s2.length() ; ++i) 
         {
             // now here we are using sliding window technique of length s1.length()
            h[s2[i]-'a']++;
            h[s2[i-s1.length()]-'a']--;
            if (w == h) return true; // check if after each operation both our frequency array is same or not
        }
        return false;
    }
};