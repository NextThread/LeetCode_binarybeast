class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> count;
        for (auto cd : cpdomains) 
        {
            int i = cd.find(" "); // find the gap index, to get the count
            int n = stoi(cd.substr (0, i)); // take the part till gap, which is the count
            string s = cd.substr (i + 1);
            for (int i = 0; i < s.size(); i++) 
            {
                if (s[i] == '.') 
                {
                    count[s.substr(i + 1)] += n; // add the count
                }
            }
            count[s] += n;
        }
        vector<string> res;
        for (auto k : count) 
        {
            res.push_back (to_string(k.second) + " " + k.first);
        }
        return res;
    }
};