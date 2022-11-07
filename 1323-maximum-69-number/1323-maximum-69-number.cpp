class Solution {
public:
    int maximum69Number (int num) {
        string n = to_string(num);
        for(int i = 0 ; i < n.length() ; i++)
            if(n[i] == '6') {
                n[i] = '9';
                break;                
            }
        return stoi(n);
    }
};