// Boyer Moore's wating algorithm based (Two Pass Solution)
// Time : O(n)
// Space : O(1)

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>&a) {
//         vector<int> ans;
//         int n = a.size();
        
//         int num1 = INT_MIN;        
//         int num2 = INT_MIN;
//         int count1 = 0;        
//         int count2 = 0;
		
//         for(int i=0;i<n;i++)
//         {
//             if(a[i]==num1) count1++;
//             else if(a[i]==num2) count2++;
//             else if(count1 == 0)
//             {
//                 num1 = a[i];
//                 count1 = 1;
//             }
//             else if(count2 == 0)
//             {
//                 num2 = a[i];
//                 count2 = 1;
//             }
//             else
//             {
//                 count1--;
//                 count2--;
//             }
//         }
//         count1 = 0;
//         count2 = 0;
//         for(int i=0;i<n;i++)
//         {
//             if(a[i]==num1) count1++;
//             else if(a[i]==num2) count2++;
//         }
//         if(count1>(n/3)) ans.push_back(num1);
//         if(count2>(n/3)) ans.push_back(num2);
//         return ans;
//     }
// };
// Map Based Solution
// Time : O(n)
// Space : O(n)

class Solution {
public:
    vector<int> majorityElement(vector<int>&nums) {     
        int n = nums.size()/3;
        vector<int> v;
        unordered_map<int, int> a;
        int c = 0;
        for(int x : nums){
            a[x]++;
        }
        for(auto d : a)
            if(d.second > n){
                c = d.first;
                v.push_back(c);
            };
        return v;
    }
};
