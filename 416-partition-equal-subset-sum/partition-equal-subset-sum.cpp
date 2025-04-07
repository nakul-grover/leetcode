class Solution {
public:
    bool solve(vector<int>&nums,int i,int sum,int total, vector<vector<int>>&dp){
        if(i>=nums.size()){
            return false;
        }
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        if(sum == total - sum) {
            return true;
        }

        bool pick = solve(nums,i+1,sum+nums[i],total,dp);
        bool notpick = solve(nums,i+1,sum,total,dp);
        return dp[i][sum] = pick || notpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;


        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        vector<vector<int>>dp(nums.size(),vector<int>(sum+1,-1));
        
        return solve(nums,0,0,sum,dp);
    }
};