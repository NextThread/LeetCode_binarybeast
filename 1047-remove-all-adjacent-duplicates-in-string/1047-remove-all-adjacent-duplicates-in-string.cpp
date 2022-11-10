class Solution {
public:
    string removeDuplicates(string S) {
        string res = "";
        for (char ch : S)
            if (res.size() && ch == res.back()) // pop elements till u get equal characters
                res.pop_back();
            else
                res.push_back(ch); // else keep pushing
        return res;
    }
};
