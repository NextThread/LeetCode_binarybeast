class Solution {
public:
    bool isPathCrossing(string path) {
        unordered_set<string> visited;
        int x = 0, y = 0;
        visited.insert(to_string(x) + "," + to_string(y));
        for (char c : path) {
            if (c == 'N') y += 1;
            else if (c == 'S') y -= 1;
            else if (c == 'E') x += 1;
            else x -= 1;
            string key = to_string(x) + "," + to_string(y);
            if (visited.count(key)) return true;
            visited.insert(key);
        }
        return false;
    }
};