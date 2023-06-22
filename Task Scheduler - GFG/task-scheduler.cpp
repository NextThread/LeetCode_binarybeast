//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
           priority_queue<int>pq;
       vector<int> arr(26,0);
       queue<pair<int,int>>q;
       //count the no. of distinct tasks
       for(auto i: tasks)
       {
           arr[i-'A']++;
       }
       //when task is greater then 0 push them to the queue.just the count of difeerent task.
       for(auto i:arr)
       {
           if(i>0)
           pq.push(i);
       }
       
       int time=0;
       
       while(pq.size()>0 or q.size()>0)
       {  

//execte the first process from heap for a unit time and hence time will increment by 1;
           time++;


            // now after execution of one unit we will check if there is remaining time
            //for the task to be completed.if yes then push the  time required to complete and
            //time when it can be resumed to the queue.


          if(pq.size()>0)  
            {
                if(pq.top()-1>0)
               {q.push({pq.top()-1,time+K});
                   
               }
           pq.pop();
           }
           
           
           //once we have pushed the task from heap and pushed it to the queue,
           //at every currtime we will check if there is a task which could be resumed and
           //hence we will pop it from queue and add it to the heap for further scheduling.
           
           
           
           if(q.size()>0 and q.front().second==time)
           {pq.push(q.front().first);
           q.pop();}
       }
       
       return time;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;

        vector<char> tasks(N);
        for (int i = 0; i < N; i++) cin >> tasks[i];

        Solution obj;
        cout << obj.leastInterval(N, K, tasks) << endl;
    }
    return 0;
}
// } Driver Code Ends