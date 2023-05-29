//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
     bool dfs(int i, int j, vector<vector<char>> &board, string &word, int idx){
        if(idx>= word.size()) return true;
        if(i<0 || j<0 || i>= board.size() || j>= board[0].size() || board[i][j]=='~' || board[i][j]!=word[idx]) return false;
        board[i][j]='~';
        return dfs(i+1, j, board, word, idx+1) || dfs(i-1, j, board, word, idx+1) || dfs(i, j+1, board, word, idx+1) || dfs(i, j-1, board, word, idx+1);
        
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(board[i][j]==word[0]){
                    if(dfs(i, j, board, word, 0)) return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
// } Driver Code Ends