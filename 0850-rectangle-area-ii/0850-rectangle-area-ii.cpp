class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        int mod = 1e9 + 7;
        vector<pair<int, int>> abscissas;
        for (int i = 0; i < rectangles.size(); i++) {
            if (rectangles[i][0] != rectangles[i][2]) {
                abscissas.emplace_back(rectangles[i][0], i);
                abscissas.emplace_back(rectangles[i][2], i);
            }
        }
        sort(abscissas.begin(), abscissas.end());
        list<pair<int, int>> current;
        long area = 0;
        int x_prev = -1;
        for (const auto& [x, i] : abscissas) {
            long height = 0;
            int cur = -1;
            for (const auto& [y_min, y_max] : current) {
                cur = max(cur, y_min);
                height += max(y_max - cur, 0);
                cur = max(cur, y_max);
            }
            area = (area + ((x - x_prev) * height)) % mod;
            if (x == rectangles[i][0]) {
                current.emplace_back(rectangles[i][1], rectangles[i][3]);
                current.sort();
            } else {
                for (auto it = current.begin(); it != current.end(); it++) {
                    if (it->first == rectangles[i][1] && it->second == rectangles[i][3]) {
                        current.erase(it);
                        break;
                    }
                }
            }
            x_prev = x;
        }
        return area;
    }
};