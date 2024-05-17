class Solution {
public:
    vector<int>result;
    unordered_map<string,int>dp;
    void solve(int index,vector<int>&peopleSkills,int target,vector<int>&temp,int mask){
        if(index>=peopleSkills.size()){
            if(mask==target && (result.size() == 0 || temp.size()<result.size())){
                result =temp;
            }
            return;
        }
        string s = to_string(index) + "_" + to_string(mask);
        if(dp.find(s) != dp.end()){
            if(dp[s] <= temp.size())
                return;
            
        }
        
        if(result.size()!=0 && temp.size()>result.size()){
            return;
        }
        solve(index+1,peopleSkills,target,temp,mask);
        
        if((mask | peopleSkills[index]) != mask){
        temp.push_back(index);
        solve(index+1,peopleSkills,target,temp,(mask| peopleSkills[index]));
        temp.pop_back();
        dp[s] = (temp.size()!=0) ? (temp.size()) : -1;
        }
    }
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string,int>skills;
        int n=req_skills.size();
        for(int i=0;i<req_skills.size();i++){
            skills[req_skills[i]]=i;
        }
        
        
        vector<int>peopleSkills;
        for(int i=0;i<people.size();i++){
            int total = 0;
            for(string skill : people[i]){
                total = total | 1<<skills[skill];
            }
            peopleSkills.push_back(total);
        }
        
        int target =pow(2,n)-1;
        vector<int>temp;
        solve(0,peopleSkills,target,temp,0);
        return result;
        
    }
};