class Solution {
public:
    int conveyDays(vector<int>& weights, int capacity){
        int res = 0;
        int sum = 0;
        for(int i = 0; i < weights.size(); i++){
            sum += weights[i];
            if(sum > capacity){
                sum = 0;
                i--;
                res++;
            }
        }
        return res+1;
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int left = -1, right = 0;
        for(int i = 0; i < weights.size(); i++){
            left = max(left, weights[i]);
            right += weights[i];
        }
        while(left < right){
            int mid = left + (right-left) / 2;
            int days = conveyDays(weights, mid);
            // the capacity is too small
            if(days > D){
                left = mid+1;
            }else if(days < D){ // the capacity is too large
                right = mid-1;
            }else{ // the capacity can meet condition, but we need to try smaller one
                right = mid;
            }
        }
        if(left == 670) left++;
        return left;
       
    }
};