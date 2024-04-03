class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word) {
    if (!word.size())
        return true;
    if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[0])   // check if exceeds boundaries
        return false;
    char c = board[i][j];
    board[i][j] = '*';
    string s = word.substr(1);
    bool ret = dfs(board, i-1, j, s) || dfs(board, i+1, j, s) || dfs(board, i, j-1, s) || dfs(board, i, j+1, s); // dfs for all four directions
    board[i][j] = c;
    return ret; // check if the dfs call is valid
    }
    
    bool exist(vector<vector<char>>& board, string word) {
    for (int i = 0; i < board.size(); i++) 
        for (int j = 0; j < board[0].size(); j++) 
            if (dfs(board, i, j, word)) // call dfs for the cell
                return true;
    return false;
    }
};
