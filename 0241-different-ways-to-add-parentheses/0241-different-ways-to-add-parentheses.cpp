class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        for (int i = 0; i< expression.size(); i++){
            if(expression[i]=='+' or expression[i]=='-' or expression[i]=='*'){
                vector<int> left = diffWaysToCompute(expression.substr(0,i));
                vector<int> right = diffWaysToCompute(expression.substr(i+1));
                
                for (int a:left)
                    for (int b:right)
                        if (expression[i] == '+')
                            res.push_back (a+b);
                        else if(expression[i] == '-')
                            res.push_back(a-b);
                        else if (expression[i] == '*')
                            res.push_back(a*b);
            }
        }
        if (res.empty()){
            res.push_back(stoi(expression));
        }
        return res;
    }
        
};