class SegmentTree {
public:
    SegmentTree(int n) : n(n) {
        sum1.assign(2 * n, 0);
        sum2.assign(2 * n, 0);
    }

    void update(int idx, int delta) {
        if(idx == 0)
            return;
        int diff1 = delta;
        int diff2 = delta * idx;

        for (int i = idx + n; i > 0; i /= 2) {
            sum1[i] += diff1;
            sum2[i] += diff2;
        }
    }

    int querySum1(int left, int right) {
        return query(sum1, left, right);
    }

    int querySum2(int left, int right) {
        return query(sum2, left, right);
    }

    int computeResult(int l, int r) {
        int sum1Val = querySum1(l, r);
        int sum2Val = querySum2(l, r);
        return sum2Val - max(l-1,0) * sum1Val;
    }

private:
    int n;
    vector<int> sum1, sum2;

    int querySingle(const vector<int>& tree, int idx) {
        return tree[idx + n];
    }

    int query(const vector<int>& tree, int left, int right) {
        int res = 0;
        for (left += n, right += n + 1; left < right; left /= 2, right /= 2) {
            if (left % 2 == 1) res += tree[left++];
            if (right % 2 == 1) res += tree[--right];
        }
        return res;
    }
};


class Solution {

    

public:
    vector<int> numberOfAlternatingGroups(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        set<pair<int, int>> groups;
        map<int, int> sizeCounts;

        SegmentTree st(n+1);
        // Function to update the set of alternating groups
        auto updateGroups = [&](int l, int r, bool adding) {
            if(l<=r) {
                int size = r - l + 1;
                if (adding) {
                    groups.insert({l, r});
                    st.update(size,1);
                } else {
                    groups.erase({l, r});
                    st.update(size,-1);
                }
            }
        };


        auto isAlternate = [&](int i) {
            return colors[i] != colors[(i - 1 + n) % n];
        };
        // Initialize the groups
        int start = 0;
        while (start < n) {
            int end = start;
            while (end+1<=n-1 && isAlternate(end+1)) {
                end = (end + 1) % n;
            }
            updateGroups(start, end, true);
            start = end+1;
        }

        vector<int> result;
        for (auto& query : queries) {
            if (query[0] == 1) {
                int size = query[1];
                if(groups.size()==1) {
                    if(colors[n-1]!= colors[0])
                        result.push_back(n);
                    else
                        result.push_back(n-size+1);
                    continue;
                }         
                int ans = st.computeResult(size,n);
                if(colors[n-1]!= colors[0]) {
                    auto it = groups.begin();
                    int sz = it->second-it->first+1;
                    if(sz>=size) {
                        ans -= sz-size+1;
                    }
                    it = groups.end();
                    it--;
                    int sz2 = it->second-it->first+1;
                    if(sz2>=size) {
                        ans -= sz2-size+1;
                    }
                    sz+=sz2;
                    if(sz>=size) {
                        ans += sz-size+1;
                    }
                }
                result.push_back(ans);
                continue;
            }  
            int index = query[1];
            int newColor = query[2];
            if (colors[index] == newColor) 
                continue;
            colors[index] = newColor;
            auto it = groups.lower_bound({index+1, index+1});
            it--;
            if (it != groups.end() && it->first <= index) {
                int l = it->first;
                int r = it->second;
                if(l==index && r==index) {
                    int l2 = l;
                    int r2 = r;

                    if(it!=groups.begin()) {
                        it--;
                        l2=it->first;
                        assert(it->second+1==index);
                        it++;
                    }

                    it++;
                    if(it!=groups.end()) {
                        r2=it->second;
                        assert(it->first-1==index);
                    }
                    updateGroups(l, r, false);
                    updateGroups(l2, r2, true);
                    if(l2!=l) {
                        updateGroups(l2, index-1, false);
                    }
                    if(r2!=r) {
                        updateGroups(index+1, r2, false);
                    }
                    continue;
                }

                if(l==index && it!=groups.begin()) {
                    it--;
                    int l2 = it->first;
                    int r2 = it->second;
                    if(r2+1 == index) {
                        updateGroups(l2, r2, false);
                        updateGroups(l2, r2+1, true);                    
                    }
                }
                if(r==index){
                    it++;
                    if(it!=groups.end()) {
                        int l2 = it->first;
                        int r2 = it->second;
                        if(index+1 == l2) {
                            updateGroups(l2, r2, false);
                            updateGroups(l2-1, r2, true);                    
                        }
                    }
                }
                updateGroups(l, r, false);
                updateGroups(l, index-1, true);
                updateGroups(index+1, r, true);

                it = groups.lower_bound({index, index});
                if(it==groups.end() || it->first>index) {
                    if(it==groups.begin()) 
                        updateGroups(index,index,true);
                    else {
                        it--;
                        if(it->second<index)
                            updateGroups(index,index,true);
                    }
                }
            } else {
                assert(false);
            }            
        }

        return result;
    }
};
