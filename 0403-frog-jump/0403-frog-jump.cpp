#include<bits/stdc++.h>
struct hashFunction
{
  size_t operator()(const pair<int , 
                    int> &x) const
  {
    return x.first ^ x.second;
  }
};

class Solution {
public:
    bool helper(int currJump , int currStone, unordered_set<pair<int, int>,hashFunction>& dp , unordered_set<int>&elements , int ans ){

        if(currStone == ans) return true;
        if(currJump==0)return false;
        if(elements.find(currStone) == elements.end()) return false;
        if(dp.find({currStone , currJump}) != dp.end()) return false;
        if(helper(currJump+1 , currStone+currJump+1 , dp , elements , ans)) return true;
        if(helper(currJump-1 , currStone+currJump-1 , dp , elements , ans)) return true;
        if(helper(currJump , currStone+currJump , dp , elements , ans)) return true;
        dp.insert({currStone , currJump});
        return false;
    }
    
    bool canCross(vector<int>& stones) {
        if(stones[1] != 1) return false;
          unordered_set<pair<int, int>,hashFunction> dp;
        unordered_set<int> elements;
        for(auto a : stones)elements.insert(a);

        return helper(1 , 1 , dp , elements, stones[stones.size()-1]);
        
    }
};