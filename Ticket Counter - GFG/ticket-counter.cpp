//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int distributeTicket(int N, int K) {
            list<int> l;
        for(int i=0;i<N;i++) l.push_back(i+1);
        while(!(l.size()==1)){
            for(int i=0;i<K;i++){
                if(l.size()==1) return l.front();
                l.pop_front();
            }
            for(int i=0;i<K;i++){
                if(l.size()==1) return l.front();
                l.pop_back();
            }
        }
        return l.front();
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        int K;
        scanf("%d",&K);
        
        Solution obj;
        int res = obj.distributeTicket(N, K);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends