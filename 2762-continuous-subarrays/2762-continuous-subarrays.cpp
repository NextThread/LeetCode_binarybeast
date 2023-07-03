class Solution {
void build(int node,int start,int end,vector<int>& tree,vector<int>& a) {
    if(start == end) tree[node] = a[start];
    else {
        int mid = (start + end) >> 1;
        build(2 * node + 1, start, mid, tree, a);
        build(2 * node + 2, mid + 1, end, tree, a);
        tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
   }
}
    
int query(int node,int start,int end,int l,int r,vector<int>& tree) {
    if(l > end || start > r) return INT_MAX;
    if(l <= start && r >= end) return tree[node];
    int q1, q2;
    int mid = (start + end) >> 1;
    q1 = query(2*node + 1, start, mid, l, r, tree);
    q2 = query(2*node + 2, mid + 1, end, l, r, tree);
    return(min(q1, q2));
}
void build1(int node,int start,int end,vector<int>& tree1,vector<int>& a) {
    if(start == end) tree1[node] = a[start];
    else {
        int mid = (start + end) >> 1;
        build1(2 * node + 1, start, mid, tree1, a);
        build1(2 * node + 2, mid + 1, end, tree1, a);
        tree1[node] = max(tree1[2 * node + 1], tree1[2 * node + 2]);
   }
}
    
int query1(int node,int start,int end,int l,int r,vector<int>& tree1) {
    if(l > end || start > r) return INT_MIN;
    if(l <= start && r >= end) return tree1[node];
    int q1, q2;
    int mid = (start + end) >> 1;
    q1 = query1(2*node + 1, start, mid, l, r, tree1);
    q2 = query1(2*node + 2, mid + 1, end, l, r, tree1);
    return(max(q1, q2));
}
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> tree(4*n), tree1(4*n);
        build(0, 0, n - 1, tree, nums);
        build1(0, 0, n - 1, tree1, nums);
        
        long long res = 0;
        for(int i = 0, j = 0; i < n; i++) {
            while(i >= j and query1(0, 0, n - 1, j, i, tree1) - query(0, 0, n - 1, j, i, tree) > 2) j++;
            res += (i - j + 1);
        }
        
        return res;
    }
};