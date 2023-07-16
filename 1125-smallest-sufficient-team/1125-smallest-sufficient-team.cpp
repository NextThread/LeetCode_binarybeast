class Solution {
public:
    vector<int> res;
    int dp[(1<<16)+1][65];
    map<int,unordered_map<string,int>> m;
    int mnTeam=INT_MAX;
    
    int solve(int mask, vector<string> &req, vector<vector<string>> &people, vector<int> &temp, int curr){
        int n=req.size();
        if(mask==(1<<n)-1){
            if(mnTeam>temp.size()){
                mnTeam=temp.size();
                res=temp;
            }
            return 0;
        }
        int count=temp.size();
        if(dp[mask][count]!=-1){
            return dp[mask][count];
        }
        int ans=INT_MAX/2;
        for(int i=curr;i<people.size();i++){
            if(people[i].size()==0){
                continue; //optimization 1
            }
            int nm=mask;
            for(int j=0;j<n;j++){
                if((nm & (1<<j))==0 && m[i][req[j]]==1){   // if this bit is not set, i.e. this skill is not yet achieved and if this guy has this skill, take in account for this skill
                    nm=nm | (1<<j);
                }
            }
            if(nm!=mask && count+1<mnTeam){ //optimization 2, we want minimum guys right, so if we push one more guy and if that increases the count of guys we already had for minimum team, do not recurse for this 
                temp.push_back(i);
                ans=min(ans,1+solve(nm,req,people,temp,i+1));
                temp.pop_back();
            }
        }   
        return dp[mask][count]=ans ; 
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int n=req_skills.size();
        int mask=0;
        for(int i=0;i<people.size();i++){
            for(int j=0;j<people[i].size();j++){
                m[i][people[i][j]]=1;
            }
        }
        vector<int> temp;
        memset(dp,-1,sizeof(dp));
        cout<<solve(mask,req_skills,people,temp,0);
        return res;
    }
};