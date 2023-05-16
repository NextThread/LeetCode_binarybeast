class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged;
        for(int x : nums1) merged.push_back(x);
        for(int x : nums2) merged.push_back(x);
        sort(merged.begin(), merged.end());
        if(merged.size() & 1) return merged[merged.size()/2];
        return double(merged[merged.size()/2]+merged[merged.size()/2-1])/2;
    }
};