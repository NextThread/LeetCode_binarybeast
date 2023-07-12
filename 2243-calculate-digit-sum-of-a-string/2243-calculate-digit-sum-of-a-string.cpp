class Solution {
public:
    string digitSum(string s, int k) {
        while(s.size() > k)
        {
            vector<string> str;
            string temp = "";
            for(int i = 0 ; i < s.size() ; i++) {
                if(temp.size() == k) {
                    str.push_back(temp);
                    temp = "";
                }
                temp += s[i];
            }
            if(temp.size()) str.push_back(temp);
            string s2 = "";
            for(int i = 0 ; i < str.size() ; i++) {
                string cur = str[i];
                int sum = 0;
                for(int j = 0 ; j < cur.size() ; j++) {
                    sum += (cur[j]-'0');
                }
                s2 += to_string(sum);
            }
            s = s2;
        }
        return s;
    }
};