class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string str = to_string(num);
        int cnt = 0;
        for(int i = 0 ; i < size(str)-k+1 ; i++) {
            string chushi = "";
            for(int j = i ; j < i+k ; j++) {
                chushi += str[j];
            }
            int nunu = stoi(chushi);
            if(nunu and num % nunu == 0) cnt++;
        }
        return cnt;
    }
};