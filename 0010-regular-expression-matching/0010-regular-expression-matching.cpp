// class Solution {
// public:
//     bool isMatch(string s, string p) {
//         return regex_match(s,regex(p));
//     }
// };


// upper code giving tle for 1 cases only







class Solution {
public:
    bool util(string s, string p, int n, int m){
    if(n <= -1 && m <= -1)
        return true;

    if(n == -1 && p[m] == '*')
        return util(s, p, n, m-2);
	
    if(n == -1 || m == -1)
        return false;
	
    if(s[n] == p[m]){
        return util(s, p, n-1, m-1);
    }
    else{
        if(p[m] == '*'){
            if(s[n] == p[m-1] || p[m-1] == '.'){
                return (util(s, p, n-1, m) || util(s, p, n, m-2));
            }
            else{
                return util(s, p, n, m-2);
            }
        }
        else if(p[m] == '.'){
           return util(s, p, n-1, m-1);
        }
        else
            return false;
    }
}

bool isMatch(string s, string p) {
    return util(s, p, s.length()-1, p.length()-1);
}
};