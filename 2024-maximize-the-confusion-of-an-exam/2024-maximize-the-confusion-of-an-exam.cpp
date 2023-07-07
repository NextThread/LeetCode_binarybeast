class Solution {
public:
    int atmostofchar(string s,char a,int k){
        int l=0,cnt=0,res=INT_MIN,n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]==a)cnt++;
            while(cnt>k){
                if(s[l]==a)cnt--;
                l++;
            }
            res=max(res,i-l+1);
        }
        return res;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
         return max(atmostofchar(answerKey,'F',k),atmostofchar(answerKey,'T',k)); // try to make F consecutive, as well as T, take the max
    }
};