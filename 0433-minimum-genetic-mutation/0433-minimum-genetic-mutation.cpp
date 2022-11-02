class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
	  set<string> st{bank.begin(),bank.end()}; // stores all the valid mutations
	  if(!st.count(end)) return -1; // base case: if the endMutation is not in the set return -1
	  queue<string> Q;
	  Q.push(start); // start the process of generating permutaion by pushing it into the queue(BFS)
	  int steps = 0;
	  string cur;
	  while(!Q.empty()) {
		  int s = Q.size();
		  while(s--) {
			cur = Q.front();
			Q.pop();
			if(cur == end) return steps; // if we reach the end of the mutation.
			st.erase(cur); // erase the cur mutation to avoid redundant checking
			// at each index we check the possibility of mutation by replcaing it with A,C,G,T   & at each index we replace and & check the possibility
        for(int i = 0 ; i < 8 ; i++) {
				string t = cur;
				t[i] = 'A';
				if(st.count(t)) Q.push(t);
				t[i] = 'C';
				if(st.count(t)) Q.push(t);
				t[i] = 'G';
				if(st.count(t)) Q.push(t);
				t[i] = 'T';
				if(st.count(t)) Q.push(t);
			}
		}
		steps++;
    }
  return -1;
    }
};