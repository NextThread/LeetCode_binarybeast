class Solution {
public:
    string reorganizeString(string S) {
        string res="";
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>>pq;
        for(auto s: S) mp[s]+=1; // count frequency
        for(auto m: mp) pq.push(make_pair(m.second,m.first)); // store in pair, frequencies with chars
        while(pq.size() > 1)
        {
            auto top1 = pq.top(); pq.pop(); // pick the top most frequency element and pop it
            auto top2 = pq.top(); pq.pop(); // pick the top most frequency element and pop it
            res += top1.second; // add both chars into our resultant string
            res += top2.second;
            top1.first -= 1; // reduce their frequencies by 1
            top2.first -= 1;
            if(top1.first > 0) pq.push(top1); // if their frequency is still positive push to the priority queue
            if(top2.first > 0) pq.push(top2);
        }
        if(!pq.empty())
        {
            if(pq.top().first > 1) return ""; // if the top chars frequency is still greater than 1, it's impossible to create
            else res += pq.top().second; // else add to the resultant string
        }
        return res;
    }
};