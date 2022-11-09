class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
      int i = m-1; //  m = size of the first array
      int j = n-1; //  n = size of the second array
      int lastPos = m + n-1; // size of the resultant array
        while(j >= 0){ // run till j reaches to 0
            if(i >= 0 && nums1[i] > nums2[j]){ // till we have the first array just check at the index which one is bigger, first array element or the second array element
                nums1[lastPos--] = nums1[i--]; 
            }
            else{
                nums1[lastPos--] = nums2[j--];
            }
        }
    }
};