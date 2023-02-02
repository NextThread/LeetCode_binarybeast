class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
      for (int i = 0; i < words.size() - 1; i++) {
        string word1 = words[i];
        string word2 = words[i + 1];
        int x = 0, y = 0;
        while (word1[x] == word2[y]) { // till both char are same in both the strings, skip them
            x++, y++;
        }
        // now these are the two indexes where characters doesn't matches
        int ind1 = order.find(word1[x]);   
        int ind2 = order.find(word2[y]);
        // now if they are in sorted order, this means char of current string should appear in the order string before the char of next string
        if (ind1 > ind2) return false;
    }
    return true;
    }
};