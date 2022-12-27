class Solution {
public:
     int firstpos(vector<int>& arr, int key) {
    int ind = -1, lo = 0, hi = arr.size()-1;
    while(lo <= hi) 
    {
        int mid = (lo+hi)>>1;
        if(arr[mid] == key) 
        {
            ind = mid;
            hi = mid-1;
        }
        else if(arr[mid]<key) 
        {
            lo = mid+1;
        } 
        else 
        {
            hi = mid-1;
        }
    }
    return ind;
}
int lastpos(vector<int>& arr, int key) {
    int ind = -1, lo = 0, hi = arr.size()-1;
    while(lo <= hi) 
    {
        int mid = (lo+hi)>>1;
        if(arr[mid] == key) 
        {
            ind = mid;
            lo = mid+1;
        }
        else if(arr[mid]<key)
        {
            lo = mid+1;
        }
        else {
            hi = mid-1;
        }
    }
    return ind;
}
    vector<int> searchRange(vector<int>& nums, int target) {
       return {firstpos(nums, target), lastpos(nums, target)};
    }
};