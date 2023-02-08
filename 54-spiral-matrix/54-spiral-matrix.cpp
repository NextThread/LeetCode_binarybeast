class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<int> res;
        int direction = 1;
        int left = 0, right = m-1, top = 0, bottom = n-1;
        while(left <= right and top <= bottom)
        {
            if(direction == 1)
            {
                direction = 2;
                for(int i = left ; i <= right ; i++) res.push_back(matrix[top][i]);
                top++;
            }
            else if(direction == 2)
            {
                direction = 3;
                for(int i = top ; i <= bottom ; i++) res.push_back(matrix[i][right]);
                right--;
            }
            else if(direction == 3)
            {
                direction = 4;
                for(int i = right ; i >= left ; i--) res.push_back(matrix[bottom][i]);
                bottom--;
            }
            else if(direction == 4)
            {
                direction = 1;
                for(int i = bottom ; i >= top ; i--) res.push_back(matrix[i][left]);
                left++;
            }
        }
        return res;
    }
};