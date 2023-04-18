class Solution {
public:
    string reverseWords(string s) {
        
        // we need to do, three types of trimming
        // 1. trimming spaces from front
        // 2. trimmnig spaces from end
        // 3. trimming spaces from middle
        
        // and first of all, lets reverse each word of the string, don't trim now
        
        vector<string> res;
        string str = "";
        int n = s.size();
        for(int i = n-1 ; i >= 0 ; i--) {
            if(s[i] != ' ') str += s[i];
            else {
                reverse(str.begin(), str.end());
                res.push_back(str);
                str = "";
            }
        }
        
        // let's convert the vector into a string with spaces
        
        string ans = "";
        for(int i = 0 ; i < res.size() ; i++) {
            ans += res[i];
            ans += ' ';
        }
        
        // below step is to add the last string if got missed while adding, eg- if "abc def  adj"
        // here last string may got missed
        
        if(str.size() != 0) {
            reverse(str.begin(), str.end());
            ans += str;
        }
        
        // remove space from front (find the index where words start from beginning)
        
        string st = "";
        int ind1 = 0;
        while(ans[ind1] == ' '){
            ind1++;
        }
        
        // remove space from end (find the index from back where words starts)
        
        int ind2 = ans.length()-1;
        while(ans[ind2] == ' '){
            ind2--;
        }
      
        // let's make a new updated string
        
        for(int i = ind1 ; i <= ind2 ; i++) st += ans[i];
        
        // remove space from middle
        
        string finl = "";
        int j = 0;

        string final_ans = "";
        for(int i = 0 ; i < st.size() ; i++) {
            if(st[i] != ' ') {
                // cout << st[i];
                final_ans += st[i];
            }
            else{
                while(st[i] == ' ') i++;
                // cout << ' ';
                final_ans += ' ';
                i--;
            }
        }
        return final_ans;
    }
};