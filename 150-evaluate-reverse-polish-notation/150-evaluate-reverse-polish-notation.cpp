class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> stn;
    for(auto s:tokens) {
        if(s.size()>1 || isdigit(s[0])) stn.push(stoi(s));
        else {
            auto x2=stn.top(); stn.pop();
            auto x1=stn.top(); stn.pop();
            switch(s[0]) {
                case '+': x1+=x2; break;
                case '-': x1-=x2; break;
                case '*': x1=(long long int)(x1*x2); break;
                case '/': x1/=x2; break;
            }
            stn.push(x1);
        }
    }
    return stn.top();
    }
};