class Solution {
public:
    double average(vector<int>& salary) {
        double sum = 0;
        double mx = *max_element(salary.begin(), salary.end());
        double mn = *min_element(salary.begin(), salary.end());
        for(auto it : salary) {
            if(it != mx and it != mn) sum += it;
        }
        return sum/(salary.size()-2);
    }
};