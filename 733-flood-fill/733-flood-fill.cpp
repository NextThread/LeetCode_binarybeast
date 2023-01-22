class Solution {
public:
    
    void f(vector<vector<int>>& image, int i, int j, int old, int color)
    {
        if(i < 0 or j < 0 or i >= image.size() or j >= image[0].size() or image[i][j] != old) return;
        image[i][j] = color;
        f(image, i+1, j, old, color);
        f(image, i, j+1, old, color);
        f(image, i-1, j, old, color);
        f(image, i, j-1, old, color);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old = image[sr][sc];
        if(image[sr][sc] != color)
            f(image, sr, sc, old, color);
        return image;
    }
};