class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldcolor, int newcolor)
    {
        // Base Case : if goes out of boundary or not equal to the oldColor
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != oldcolor) return;
        image[sr][sc] = newcolor; // apply the new color & call dfs for all 4 directions
        dfs(image, sr+1, sc, oldcolor, newcolor);
        dfs(image, sr-1, sc, oldcolor, newcolor);
        dfs(image, sr, sc+1, oldcolor, newcolor);
        dfs(image, sr, sc-1, oldcolor, newcolor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if(image[sr][sc] != color)
          dfs(image, sr, sc, image[sr][sc], color);
        return image;
    }
};