class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
      int ans = INT_MAX;
        for( int i = 0 ; i < words.size() ; ++i )
        {
            if(words[i] == target)
            {
                int forward = abs(startIndex-i);
                int backward = words.size()-forward;
                ans = min(ans, min(forward, backward));
            }
        }
        return (ans == INT_MAX) ? -1 : ans;
    }
};