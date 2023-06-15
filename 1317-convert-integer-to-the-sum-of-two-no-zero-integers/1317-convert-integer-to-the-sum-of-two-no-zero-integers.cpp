class Solution {
public:
    
    bool isok(string a) {
        for(char ch : a) {
            if(ch == '0') return false;
        }
        return true;
    }
    
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1 ; i < n ; i++) {
            for(int j = 1 ; j < n ; j++) {
                if(i + j == n) {
                    string test1 = to_string(i);
                    string test2 = to_string(j);
                    if(isok(test1) and isok(test2)) return {i, j};
                }
            }
        }
        return {};
    }
};