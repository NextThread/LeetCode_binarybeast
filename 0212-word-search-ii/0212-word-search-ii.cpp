/*  
Steps--->
1.   Do backtracking to try all possible paths in the board.
2.   To check if the current path exists any word, we can build Trie
3.   Rest is Trie implementation

*/

struct TrieNode {   // Implementation of Trie Data Structure
    TrieNode* children[26] = {};
    string* word;
    void addWord(string& word) {
        TrieNode* cur = this;
        for (char c : word) {
            c -= 'a';
            if (cur->children[c] == nullptr) cur->children[c] = new TrieNode();
            cur = cur->children[c];
        }
        cur->word = &word;
    }
};

class Solution {
public:
    int m, n;
    int DIR[5] = {0, 1, 0, -1, 0};
    vector<string> ans;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(); n = board[0].size();
        TrieNode trieNode;
        for (string& word : words) trieNode.addWord(word);
        
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                dfs(board, r, c, &trieNode); // for every char, call dfs
        return ans;
    }
  
    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* cur) {
        if (r < 0 || r == m || c < 0 || c == n || board[r][c] == '#' || cur->children[board[r][c]-'a'] == NULL) return;
        char orgChar = board[r][c];
        cur = cur->children[orgChar - 'a'];
        if (cur->word != nullptr) {
            ans.push_back(*cur->word);
            cur->word = nullptr; 
        }
        board[r][c] = '#'; // mark as visited
        for (int i = 0; i < 4; ++i) dfs(board, r + DIR[i], c + DIR[i+1], cur);
        board[r][c] = orgChar; // restore the org state
    }
};