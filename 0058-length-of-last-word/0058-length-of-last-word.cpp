class Solution {
public:
    int lengthOfLastWord(string s) {
       //  int c=0;
       // int l=s.length();
       //  for(int i=l-1;i>=0;i--){
       //      if(s[i]==' ' && i==l-1){
       //          l--;
       //          continue;
       //      }
       //      else if(s[i]==' ')
       //          break;
       //      else
       //          c++;
       //  }
       //  return c;
        int cnt = 0;
        int i = 1;
        int n = s.length();
        if(s[n-1]==' '){
            while(s[n-i]==' ')i++;
        }
        for(int j = n-i ; j >= 0 ; j--){
            if(s[j]!=' ')cnt++;
            else break;
        }
        return cnt;
    }
};