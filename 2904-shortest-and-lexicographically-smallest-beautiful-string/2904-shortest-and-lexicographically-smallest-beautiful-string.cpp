class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> ans;
        for(int i=0;i<s.size();i++){
            string str;
            for(int j=i;j<s.size();j++){
                str+=s[j];
                ans.push_back(str);
            }
        }
        string res="";
        for(auto a:ans){
            int cnt=0;
            for(int i=0;i<a.size();i++) if(a[i]=='1') cnt++;
            if(cnt==k) if(res==""||res.size()>a.size() || (res.size()==a.size() && res>a)) res=a;
        }
        return res;
    }
};