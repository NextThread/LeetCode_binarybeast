class Solution {
public:
    string customSortString(string order, string s) {
        string c="";
        for(int i=0;i<order.length();i++){
            for(int j=0;j<s.length();j++){
                if(order[i]==s[j])c+=order[i];
            }
        }
        for(int i=0;i<s.length();i++){
            int flag=0;
            for(int j=0;j<order.length();j++){
                if(s[i]==order[j]){
                    flag=1;
                }
            }
            if(flag==0)c+=s[i];
        }
        return c;
    }
};