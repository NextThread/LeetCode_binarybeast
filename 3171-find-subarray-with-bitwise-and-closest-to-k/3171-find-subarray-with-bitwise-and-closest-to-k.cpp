class Solution {
public:
    vector<int> tree;

    int build(int node , int low , int high , vector<int> &nums){
        if(low == high) return tree[node] = nums[low];
        int mid = (low + high) >> 1;
        return tree[node] = build(node << 1 , low , mid , nums) & build(node << 1 | 1 , mid + 1 , high , nums);
    }

    int bitwiseAnd(int node , int low , int high , int ql , int qr){
        if(high < ql || low > qr) return (1LL << 31) - 1;
        if(low >= ql && high <= qr) return tree[node];
        int mid = (low + high) >> 1;
        return bitwiseAnd(node << 1 , low , mid , ql , qr) & bitwiseAnd(node << 1 | 1 , mid + 1 , high , ql , qr);
    }

    int minimumDifference(vector<int> &nums, int k){
        int n = nums.size() , minDiff = 1e9;
        tree.resize(n<<2|1);
        build(1 , 0 , n-1 , nums);
        for(int L = 0 ; L < n ; L++){
            int low = L , high = n - 1;
            while(low <= high){
                int R = (low + high) / 2;
                int V = bitwiseAnd(1 , 0 , n - 1 , L , R);
                minDiff = min(minDiff , abs(k - V));
                if(V < k) high = R - 1;
                else if(V > k) low = R + 1;
                else return minDiff;
            }
        }
        return minDiff;
    }
};
