class Solution {
public:
    int addedInteger(vector<int>& num1, vector<int>& num2) {
        return *min_element(num2.begin(),num2.end())-*min_element(num1.begin(),num1.end());
    }
};