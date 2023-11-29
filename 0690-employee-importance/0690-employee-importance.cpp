/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    unordered_map<int, Employee*> mp;
    
    int getSum(int& id) {      
        int sum = mp[id]->importance;
        
        for(int &ID : mp[id]->subordinates) {
            sum += getSum(ID);
        }
            
        return sum;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        mp.clear();
        
        for(int i = 0; i<employees.size(); i++)
            mp[employees[i]->id] = employees[i];
        
        return getSum(id);
        
    }
};