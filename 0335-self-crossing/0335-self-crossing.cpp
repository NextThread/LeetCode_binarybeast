class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int pos = -1;
        int n = distance.size();
        for (int i = 2; i < n; i++) {
            if (distance[i] >= distance[i - 2] && pos != -1) {
                return true; // Tried to expand or static after contracting phase
            } else if (distance[i] <= distance[i - 2] && pos == -1) {
                pos = i; // The contracting phase starts at this edge
            }
        }
        if (pos == -1) return false;
        return ((pos >= 0 ? distance[pos] : 0) + (pos >= 4 ? distance[pos - 4] : 0) >= (pos >= 2 ? distance[pos - 2] : 0)) && 
            ((pos < n - 1 ? distance[pos + 1] : 0) + (pos >= 3 ? distance[pos - 3] : 0) >= (pos >= 1 ? distance[pos - 1] : 0));
    }
};