class Solution {
public:
    
    bool is3dig(int n) {
        string str = to_string(n);
        return size(str) == 3;
    }
    
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;
        for(int i = 0 ; i < digits.size() ; i++)
        {
            for(int j = 0 ; j < digits.size() ; j++) 
            {
                for(int k = 0 ; k < digits.size() ; k++)
                {
                    if(i != j and j != k and i != k){
                    int num = digits[i];
                    num *= 10;
                    num += digits[j];
                    num *= 10;
                    num += digits[k];
                    if((num >= 100 and num <= 999) and num % 2 == 0) res.push_back(num);
                    }
                }
            }
        }
        
        set<int> st;
        for(int x : res) st.insert(x);
        
        res.clear();
        for(auto it : st) res.push_back(it);
        return res;
    }
};