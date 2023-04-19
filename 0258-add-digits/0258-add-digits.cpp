class Solution {
public:
    int addDigits(int num) {
        string s = to_string(num);
        while(s.size() > 1) {
            int temp = 0;
            while(num) {
                temp += num % 10;
                num /= 10;
            }
            num = temp;
            s = to_string(num);
        }
        return num;
    }
};