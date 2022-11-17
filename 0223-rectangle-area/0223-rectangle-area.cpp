class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) { 
        int firstRectangleArea = (C - A) * (D - B); // (x2-x1)*(y2-y1)
        int secondRectangleArea = (G - E) * (H - F); // (x2-x1)*(y2-y1)
        
        if(A >= G || B >= H || C <= E || D <= F) { // if they don't intersect each other, just return the sum of both the rectangles area
            return firstRectangleArea + secondRectangleArea;
        }
        // if they intersect each other, take out the intersect part and substract from the total sum-up area
        int length = min(C, G) - max(A, E);
        int height = min(D, H) - max(B, F);
        // substract the intersect part from the sum of area, of both the rectangle
        return firstRectangleArea + secondRectangleArea - length * height;
        
    }
};