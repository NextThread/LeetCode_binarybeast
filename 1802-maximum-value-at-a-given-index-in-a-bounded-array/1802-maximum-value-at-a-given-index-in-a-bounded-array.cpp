class Solution {
public:
    int maxValue(int n, int index, int maxSum) {
        int maxValue = 1;
        maxSum -= n;
        int layer = 1;
        
 
        int points;
        while ( maxSum > 0 ) {
            points = (2 * layer - 1);
            
            int right = (index + layer-1) - (n-1);
            if (right > 0)  points -= right;
            int left = (layer - index - 1);
            if (left > 0)  points -= left;
           
            if (points >= n || maxSum < points) break;
            
            maxSum -= points;
            layer++;
            maxValue++;
        }
        return maxValue += (maxSum/n);
    }
};