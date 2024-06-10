class Solution {
public:
    
    int solve(int i,int k,vector<int>&nums,vector<vector<int>>&dp){
        if(i==nums.size()){
            return 0;
        }
        if(dp[i][k]!=-1){
            return dp[i][k];
        }
        int maxLen = 1;
        for(int j=i-1;j>=0;j--){
            if(nums[i]==nums[j]){
                maxLen =max(maxLen,1+solve(j,k,nums,dp));
            }
            else if(nums[i]!=nums[j] && k>0){
                maxLen =max(maxLen,1+solve(j,k-1,nums,dp));
            }
        }
        return dp[i][k]=maxLen;
    }
    int maximumLength(vector<int>& nums, int k) {
        int maxLen=0;
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(min(n+1,26),-1));
        for(int i=0;i<n;i++){
            maxLen=max(maxLen,solve(i,k,nums,dp));
            }
        return maxLen;
    }
};