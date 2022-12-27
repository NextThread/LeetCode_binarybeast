class Solution {
public:
     int firstpos(vector<int>& arr, int key) {
        int pos = -1, s = 0, e = arr.size()-1;
        while(s <= e) {
            int mid = (s+e)>>1;
            if(arr[mid] == key) {
                pos = mid;
                e = mid-1;
            } else if(arr[mid]<key) {
                s = mid+1;
            } else e = mid-1;
        }
        return pos;
    }
     int lastpos(vector<int>& arr, int key) {
        int pos = -1, s = 0, e = arr.size()-1;
        while(s <= e) {
            int mid = (s+e)>>1;
            if(arr[mid] == key) {
                pos = mid;
                s = mid+1;
            } else if(arr[mid]<key){
                s = mid+1;
            } else e = mid-1;
        }
        return pos;
     }
    vector<int> searchRange(vector<int>& nums, int target) {
       return {firstpos(nums, target), lastpos(nums, target)};
    }
};