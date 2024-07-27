class Solution {
public:
    int solve(vector<int>&prices,int index,int buy,vector<vector<int>>&dp){
        if(index==prices.size()){
            return 0;
        }
        if(dp[index][buy]!=-1){
            return dp[index][buy];
        }
             int ans=INT_MIN;
        if(buy==1){
            int bought=(-1)*prices[index]+solve(prices,index+1,0,dp);
            int skip=solve(prices,index+1,1,dp);
            ans=max(bought,skip);
        }
        if(buy==0){
            int sold=prices[index]+solve(prices,index+1,1,dp);
            int skip=solve(prices,index+1,0,dp);
            ans=max(sold,skip);
        }
        return dp[index][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
       int n= prices.size()+1;
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(prices,0,1,dp);
        
    }
};