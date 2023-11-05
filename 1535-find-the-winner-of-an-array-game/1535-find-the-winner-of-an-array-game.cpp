class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int p1 = 0, p2 = 1, r;
        int mx = *max_element(arr.begin(), arr.end());
        vector<int> wins(mx+1, 0);
        int c = 0;
        while(c != arr.size()-1) {
            if (arr[p1] == mx || arr[p2] == mx) return mx;
            if (arr[p1] > arr[p2]) {
                wins[arr[p1]]++;
                if (wins[arr[p1]] >= k) return arr[p1];
                p2++;
            } else {
                wins[arr[p2]]++;
                if (wins[arr[p2]] >= k) return arr[p2];
                r = p2+1;
                p1 = p2;
                p2 = r;
            }
            c++;
        }
        return mx;
    }
};