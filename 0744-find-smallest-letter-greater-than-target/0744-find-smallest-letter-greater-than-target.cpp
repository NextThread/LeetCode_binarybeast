class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char res = '|';
        for(char ch : letters) {
            if(ch > target) {
                res = min(res, ch);
            }
        }
        if(res == '|') return letters[0];
        return res;
    }
};