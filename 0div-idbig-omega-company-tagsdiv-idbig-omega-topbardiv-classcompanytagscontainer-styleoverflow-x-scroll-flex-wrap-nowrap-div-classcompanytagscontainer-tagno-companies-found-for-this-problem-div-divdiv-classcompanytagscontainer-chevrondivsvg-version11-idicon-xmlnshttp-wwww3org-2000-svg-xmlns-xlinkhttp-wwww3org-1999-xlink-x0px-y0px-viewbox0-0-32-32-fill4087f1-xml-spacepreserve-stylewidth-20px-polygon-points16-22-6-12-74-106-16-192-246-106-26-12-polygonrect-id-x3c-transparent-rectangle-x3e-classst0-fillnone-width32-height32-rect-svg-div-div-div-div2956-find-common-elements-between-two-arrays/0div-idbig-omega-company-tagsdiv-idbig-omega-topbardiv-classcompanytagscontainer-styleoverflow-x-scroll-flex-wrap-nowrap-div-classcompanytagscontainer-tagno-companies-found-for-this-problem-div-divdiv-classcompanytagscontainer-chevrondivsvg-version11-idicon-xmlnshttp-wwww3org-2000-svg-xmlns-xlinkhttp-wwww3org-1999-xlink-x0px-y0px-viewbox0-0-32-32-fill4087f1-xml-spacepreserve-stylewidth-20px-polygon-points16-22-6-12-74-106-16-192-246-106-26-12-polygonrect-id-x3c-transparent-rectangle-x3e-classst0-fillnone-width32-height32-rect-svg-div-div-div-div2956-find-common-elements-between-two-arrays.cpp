class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1(nums1.begin(), nums1.end());
        set<int> set2(nums2.begin(), nums2.end());
        int count1 = 0, count2 = 0;
        for (auto it : nums1) count1 += set2.count(it);
        for (auto it : nums2) count2 += set1.count(it);
        return {count1, count2};
    }
};